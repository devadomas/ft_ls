/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:07:56 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/30 17:04:04 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

static void		print_file_type(t_file *file)
{
	struct stat		*sb;

	sb = file->sb;
	if (file->symlink)
		ft_putchar('l');
	else if (S_ISREG(sb->st_mode))
		ft_putchar('-');
	else if (S_ISDIR(sb->st_mode))
		ft_putchar('d');
	else if (S_ISBLK(sb->st_mode))
		ft_putchar('b');
	else if (S_ISCHR(sb->st_mode))
		ft_putchar('c');
	else if (S_ISFIFO(sb->st_mode))
		ft_putchar('p');
	else if (S_ISSOCK(sb->st_mode))
		ft_putchar('s');
}

static void		print_permissions(t_file *file)
{
	struct stat		*sb;

	sb = file->sb;
	print_file_type(file);
	ft_putchar((sb->st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((sb->st_mode & S_IWUSR) ? 'w' : '-');
	if (sb->st_mode & S_ISUID)
		ft_putchar((sb->st_mode & S_IXUSR) ? 's' : 'S');
	else
		ft_putchar((sb->st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((sb->st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((sb->st_mode & S_IWGRP) ? 'w' : '-');
	if (sb->st_mode & S_ISGID)
		ft_putchar((sb->st_mode & S_IXGRP) ? 's' : 'S');
	else
		ft_putchar((sb->st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((sb->st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((sb->st_mode & S_IWOTH) ? 'w' : '-');
	if (sb->st_mode & S_ISVTX)
		ft_putchar((sb->st_mode & S_IXOTH) ? 't' : 'T');
	else
		ft_putchar((sb->st_mode & S_IXOTH) ? 'x' : '-');
	print_acl(file);
	ft_putchar(' ');
}

static char		*splice_year(char *str, char **formatted)
{
	char		*ret;
	int			i;
	int			b;

	free(*formatted);
	i = 20;
	while (str[i] == ' ')
		i++;
	b = i;
	while (ft_isdigit(str[b]))
		b++;
	ret = ft_strsub(str, i, b - i);
	*formatted = ret;
	return (ret);
}

static void		print_date(t_file *file, t_opt *opt)
{
	time_t			now;
	time_t			calc;
	char			*time_str;
	char			*formatted;

	if (!(file->sb))
		return ;
	time(&now);
	time_str = ctime((opt->flag_u ? &file->sb->st_atime : &file->sb->st_mtime));
	calc = now - (opt->flag_u ? (file->sb)->st_atime : (file->sb)->st_mtime);
	if (ABS(calc) > 15724800)
	{
		formatted = ft_strsub(time_str, 4, 7);
		ft_putstr(formatted);
		splice_year(time_str, &formatted);
		ft_putchar(' ');
		ft_putstr(formatted);
		free(formatted);
		ft_putchar(' ');
		return ;
	}
	formatted = ft_strsub(time_str, 4, 12);
	ft_putstr(formatted);
	free(formatted);
	ft_putchar(' ');
}

void			format_long(t_file *files, t_opt *options, t_bool long_mode)
{
	print_total(files, options, long_mode);
	while (files)
	{
		if (!(is_file_hidden(files->filename) && !(options->include_hidden)))
		{
			print_permissions(files);
			print_nbr((files->sb)->st_nlink, options->hlink_offset, 1, 1);
			if (!(options->flag_g))
				print_str(files->uname, options->owner_offset, 0, 1);
			if ((!(options->flag_o) && !(options->flag_g)) ||
					(options->flag_g && options->flag_o))
				ft_putchar(' ');
			if (!(options->flag_o))
				print_str(files->gname, options->group_offset, 0, 1);
			print_nbr((files->sb)->st_size, options->size_offset + 1, 1, 1);
			print_date(files, options);
			color_output(files, options);
			print_symlink(files);
			ft_putchar('\n');
		}
		files = files->next;
	}
}
