/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:07:56 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/28 19:45:01 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

#include <stdio.h>

static void		print_file_type(t_file *file)
{
	if (S_ISDIR((file->sb)->st_mode))
		ft_putchar('d');
	else
		ft_putchar((file->symlink ? 'l' : '-'));
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
	ft_putchar((listxattr(file->path, NULL, 0, XATTR_NOFOLLOW) > 0 ? '@' : ' '));
	//printf(" ");
	ft_putchar(' ');
}

static char		*splice_year(char *str)
{
	char		*ret;
	int			i;
	int			b;

	i = 20;
	while (str[i] == ' ')
		i++;
	b = i;
	while (ft_isdigit(str[b]))
		b++;
	ret = ft_strsub(str, i, b - i);
	return (ret);
}

static void		print_date(t_file *file)
{
	time_t			now;
	time_t			calc;
	char			*time_str;
	char			*formatted;

	if (!(file->sb))
		return ;
	time(&now);
	time_str = ctime(&(file->sb)->st_mtime);
	calc = now - (file->sb)->st_mtime;
	if (ABS(calc) > 15724800)
	{
		formatted = ft_strsub(time_str, 4, 7);
		//printf("%s", formatted);
		ft_putstr(formatted);
		free(formatted);
		formatted = splice_year(time_str);
		//printf(" %s", formatted);
		ft_putchar(' ');
		ft_putstr(formatted);
		free(formatted);
	}
	else
	{
		formatted = ft_strsub(time_str, 4, 12);
		//printf("%s", formatted);
		ft_putstr(formatted);
		free(formatted);
	}
}

void			format_long(t_file *files, t_opt *options, t_bool long_mode)
{
	int		count;

	count = get_file_list_len(files, options->include_hidden);
	if (long_mode && count)
	{
		//printf("total %d\n", options->total);
		ft_putstr("total ");
		ft_putnbr(options->total);
		ft_putchar('\n');
	}
	while (files)
	{
		if (!(is_file_hidden(files->filename) && !(options->include_hidden)))
		{
			print_permissions(files);
			//printf("%*d ", options->hlink_offset, (files->sb)->st_nlink);
			print_nbr((files->sb)->st_nlink, options->hlink_offset, TRUE, TRUE);
			//printf("%-*s ", options->owner_offset, files->uname);
			print_str(files->uname, options->owner_offset, FALSE, TRUE);
			//printf(" %-*s ", options->group_offset, files->gname);
			ft_putchar(' ');
			print_str(files->gname, options->group_offset, FALSE, TRUE);
			//printf("%*lld ", options->size_offset + 1, (files->sb)->st_size);
			print_nbr((files->sb)->st_size, options->size_offset + 1, 1, 1);
			print_date(files);
			//printf(" %s", files->filename);
			ft_putchar(' ');
			ft_putstr(files->filename);
			if (files->symlink)
			{
				//printf(" -> %s", files->symlink);
				ft_putstr(" -> ");
				ft_putstr(files->symlink);
			}
			//printf("\n");
			ft_putchar('\n');
		}
		files = files->next;
	}
}
