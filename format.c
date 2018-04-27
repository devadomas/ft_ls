/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:11:39 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/27 10:04:20 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

#include <stdio.h>

static void		print_permissions(t_file *file)
{
	struct stat		*sb;
	ssize_t xattr;

	if (!(file->sb))
	{
		printf("----------");
		return ;
	}
	xattr = 0;
	sb = file->sb;
	if (S_ISDIR(sb->st_mode))
		printf("d");
	else
		printf((file->symlink ? "l" : "-"));
	printf((sb->st_mode & S_IRUSR) ? "r" : "-");
	printf((sb->st_mode & S_IWUSR) ? "w" : "-");
	printf((sb->st_mode & S_IXUSR) ? "x" : "-");
	printf((sb->st_mode & S_IRGRP) ? "r" : "-");
	printf((sb->st_mode & S_IWGRP) ? "w" : "-");
	printf((sb->st_mode & S_IXGRP) ? "x" : "-");
	printf((sb->st_mode & S_IROTH) ? "r" : "-");
	printf((sb->st_mode & S_IWOTH) ? "w" : "-");
	printf((sb->st_mode & S_IXOTH) ? "x" : "-");
	xattr = listxattr(file->path, NULL, 0, XATTR_NOFOLLOW);
	printf((xattr == 0 ? " " : "@"));
}

static void		print_hard_links(t_file *file, t_opt *options)
{
	if (!(file->sb))
	{
		printf("%*d", options->hlink_offset, 0);
		return ;
	}
	printf("%*d", options->hlink_offset, (file->sb)->st_nlink);
}

static void		print_owner(t_file *file, t_opt *options)
{
	if (!(file->uname))
		return ;
	printf("%-*s", options->owner_offset, file->uname);
}

static void		print_group(t_file *file, t_opt *options)
{
	if (!(file->gname))
		return ;
	printf(" %-*s", options->group_offset, file->gname);
}

static void		print_size(t_file *file, t_opt *options)
{
	if (!(file->sb))
	{
		printf("%*d", options->size_offset + 1, 0);
		return ;
	}
	printf("%*lld", options->size_offset + 1, (file->sb)->st_size);
}

static void		print_date(t_file *file, t_opt *options)
{
	time_t			now;
	char			*time_str;
	char			*formatted;

	(void)options;
	if (!(file->sb))
	{
		printf("XXX XX XX:XX");//to fix
		return ;
	}
	time(&now);
	time_str = ctime(&(file->sb)->st_mtime);
	// time_str example: "Mon Apr 23 20:10:38 2018\n"
	if (ABS(now - (file->sb)->st_mtime) > 13132800)
	{
		formatted = ft_strsub(time_str, 4, 7);
		printf("%s", formatted);
		free(formatted);
		formatted = ft_strsub(time_str, 20, 4);
		printf("%5s", formatted); /* don't know if gap needed - date len (5) */
		free(formatted);
	}
	else
	{
		formatted = ft_strsub(time_str, 4, 12);
		printf("%s", formatted);
		free(formatted);
	}
}

static void		format_long(t_file *files, t_opt *options)
{
	printf("total %d\n", options->total);
	while (files)
	{
		if (!(is_file_hidden(files->filename) && !(options->include_hidden)))
		{
			print_permissions(files);
			printf(" ");
			print_hard_links(files, options);
			printf(" ");
			print_owner(files, options);
			printf(" ");
			print_group(files, options);
			printf(" ");
			print_size(files, options);
			printf(" ");
			print_date(files, options);

			printf(" %s", files->filename);
			if (files->symlink)
				printf(" -> %s", files->symlink);
			printf("\n");
		}
		files = files->next;
	}
}

static void		format_cols(t_file *files, t_opt *options, int cols)
{
	int		i;
	int		j;
	int		len;
	int		index;
	t_file	*file;

	i = 0;
	len = get_file_list_len(files, options->include_hidden);
	if (len != 1)
		len = ft_floor_up((float)len / cols);
	//printf("%d / %d Calculus: %d\n", size, len, calc);
	while (i++ < len)
	{
		j = 0;
		while (j++ < cols)
		{	
			index = (i - 1) + (j - 1) * (len);
			//printf("%-*d", options->title_offset + 1, index);
			file = get_nth_file(files, index, options->include_hidden);
			if (!file) /* Not sure */
				break ;
			printf("%-*s", options->title_offset + 1, file->filename);
		}
		printf("\n");
	}
}

void		format_simple(t_file *files, t_opt *options)
{
	while (files)
	{
		if (!(is_file_hidden(files->filename) && !(options->include_hidden)))
			printf("%s\n", files->filename);
		files = files->next;
	}
}

void			format_output(t_file *files, t_opt *options)
{
	int cols;

	/*
	 * TODO: ignoring other flags
	 */
	if (options->long_list) /* formatting -l option */
		format_long(files, options);

	else if (options->one)
		format_simple(files, options);
	else 
	{
		cols = (options->window)->ws_col / (options->title_offset + 1);
		/*printf("widht: %d | can fit: %d | title: %d\n",
				(options->window)->ws_col, cols, options->title_offset);*/
		if (!cols)
			format_simple(files, options);
		else
			format_cols(files, options, cols);
	}
}
