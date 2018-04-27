/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:11:39 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/27 18:40:56 by azaliaus         ###   ########.fr       */
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
	if (sb->st_mode & S_ISUID)
		printf((sb->st_mode & S_IXUSR) ? "s" : "S");
	else
		printf((sb->st_mode & S_IXUSR) ? "x" : "-");
	printf((sb->st_mode & S_IRGRP) ? "r" : "-");
	printf((sb->st_mode & S_IWGRP) ? "w" : "-");
	if (sb->st_mode & S_ISGID)
		printf((sb->st_mode & S_IXGRP) ? "s" : "S"); // not sure if S or l
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
	time_t			calc;
	char			*time_str;
	char			*formatted;
	int 			i;

	(void)options;
	if (!(file->sb))
		return ;
	time(&now);
	time_str = ctime(&(file->sb)->st_mtime);
	/* time_str example: "Mon Apr 23 20:10:38 2018\n" */
	calc = now - (file->sb)->st_mtime;
	if (ABS(calc) > 15724800) //13132700
	{
		formatted = ft_strsub(time_str, 4, 7);
		printf("%s", formatted);
		free(formatted);
		/* Needs to be moved in to different command */
		i = 20;
		while (time_str[i] == ' ')
			i++;
		int b;
		b = i;
		while(ft_isdigit(time_str[b]))
			b++;
		formatted = ft_strsub(time_str, i, b - i);
		/* /--- */
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

static void		format_long(t_file *files, t_opt *options, t_bool long_mode)
{
	int count;

	count = get_file_list_len(files, options->include_hidden); // eats speed
	if (long_mode && count)
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
	while (i++ < len)
	{
		j = 0;
		while (j++ < cols)
		{	
			index = (i - 1) + (j - 1) * (len);
			file = get_nth_file(files, index, options->include_hidden);
			if (!file)
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

void			format_output(t_file *files, t_opt *options, t_bool long_mode)
{
	int cols;

	/*
	 * TODO: ignoring other flags
	 */
	if (options->long_list)
		format_long(files, options, long_mode);
	else if (options->one)
		format_simple(files, options);
	else 
	{
		cols = (options->window)->ws_col / (options->title_offset + 1);
		if (!cols)
			format_simple(files, options);
		else
			format_cols(files, options, cols);
	}
}
