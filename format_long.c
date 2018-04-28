/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:07:56 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/28 18:37:35 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

#include <stdio.h>

static void		print_permissions(t_file *file)
{
	struct stat		*sb;
	ssize_t			xattr;

	xattr = 0;
	sb = file->sb;
	if (S_ISDIR(sb->st_mode))
		printf("d");
	else
		printf((file->symlink ? "l" : "-"));
	printf((sb->st_mode & S_IRUSR) ? "r" : "-");
	printf((sb->st_mode & S_IWUSR) ? "w" : "-");
	if (sb->st_mode & S_ISUID)
		printf((sb->st_mode & S_IXUSR) ? "s" : "S");
	else
		printf((sb->st_mode & S_IXUSR) ? "x" : "-");
	printf((sb->st_mode & S_IRGRP) ? "r" : "-");
	printf((sb->st_mode & S_IWGRP) ? "w" : "-");
	if (sb->st_mode & S_ISGID)
		printf((sb->st_mode & S_IXGRP) ? "s" : "S");
	else
		printf((sb->st_mode & S_IXGRP) ? "x" : "-");
	printf((sb->st_mode & S_IROTH) ? "r" : "-");
	printf((sb->st_mode & S_IWOTH) ? "w" : "-");
	if (sb->st_mode & S_ISVTX)
		printf((sb->st_mode & S_IXOTH) ? "t" : "T");
	else
		printf((sb->st_mode & S_IXOTH) ? "x" : "-");
	xattr = listxattr(file->path, NULL, 0, XATTR_NOFOLLOW);
	printf((xattr > 0 ? "@" : " "));
	printf(" ");
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
		printf("%s", formatted);
		free(formatted);
		formatted = splice_year(time_str);
		printf(" %s", formatted);
		free(formatted);
	}
	else
	{
		formatted = ft_strsub(time_str, 4, 12);
		printf("%s", formatted);
		free(formatted);
	}
}

void			format_long(t_file *files, t_opt *options, t_bool long_mode)
{
	int		count;

	count = get_file_list_len(files, options->include_hidden);
	if (long_mode && count)
		printf("total %d\n", options->total);
	while (files)
	{
		if (!(is_file_hidden(files->filename) && !(options->include_hidden)))
		{
			print_permissions(files);
			printf("%*d ", options->hlink_offset, (files->sb)->st_nlink);
			printf("%-*s ", options->owner_offset, files->uname);
			printf(" %-*s ", options->group_offset, files->gname);
			printf("%*lld ", options->size_offset + 1, (files->sb)->st_size);
			print_date(files);
			printf(" %s", files->filename);
			if (files->symlink)
				printf(" -> %s", files->symlink);
			printf("\n");
		}
		files = files->next;
	}
}
