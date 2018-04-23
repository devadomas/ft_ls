/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:11:39 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/23 16:56:44 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

#include <stdio.h>

static void		print_permissions(char *file_path)
{
	struct stat		sb;

	if (stat(file_path, &sb) < 0)
	{
		printf("----------");
		return ;
	}
	printf((S_ISDIR(sb.st_mode)) ? "d" : "-");
	printf((sb.st_mode & S_IRUSR) ? "r" : "-");
	printf((sb.st_mode & S_IWUSR) ? "w" : "-");
	printf((sb.st_mode & S_IXUSR) ? "x" : "-");
	printf((sb.st_mode & S_IRGRP) ? "r" : "-");
	printf((sb.st_mode & S_IWGRP) ? "w" : "-");
	printf((sb.st_mode & S_IXGRP) ? "x" : "-");
	printf((sb.st_mode & S_IROTH) ? "r" : "-");
	printf((sb.st_mode & S_IWOTH) ? "w" : "-");
	printf((sb.st_mode & S_IXOTH) ? "x" : "-");
	printf(" "); // don't know if is needed for @ tag
}

static void		print_hard_links(char *file_path, t_opt *options)
{
	struct stat		sb;

	if (stat(file_path, &sb) < 0)
	{
		printf("%*d", options->hlink_offset, 0);
		return ;
	}
	printf("%*d", options->hlink_offset, sb.st_nlink);
}

static void		print_owner(char *file_path, t_opt *options)
{
	struct stat		sb;
	struct passwd 	*usr;

	if (stat(file_path, &sb) < 0)
	{
		printf("%*s", options->owner_offset, "unknown"); // make sure about this one
		return ;
	}
	usr = getpwuid(sb.st_uid);
	if (!usr)
		return ;
	printf("%*s", options->owner_offset, usr->pw_name);
	//free(usr);
}

static void		print_group(char *file_path, t_opt *options)
{
	struct stat		sb;
	struct group	*usr;

	if (stat(file_path, &sb) < 0)
	{
		printf("%*s", options->group_offset + 1, "unknown");
		// make sure about this one
		return ;
	}
	usr = getgrgid(sb.st_gid);
	if (!usr)
		return ;
	printf("%*s", options->group_offset + 1, usr->gr_name);
	//free(usr);
}

static void		print_size(char *file_path, t_opt *options)
{
	struct stat		sb;

	if (stat(file_path, &sb) < 0)
	{
		printf("%*d", options->size_offset + 1, 0);
		return ;
	}
	printf("%*lld", options->size_offset + 1, sb.st_size);
}

void			format_output(t_file *file, t_opt *options)
{
	if (is_file_hidden(file->filename) && !(options->include_hidden))
		return ;
	if (options->long_list) /* formatting -l option */
	{
		print_permissions(file->path);
		printf(" ");
		print_hard_links(file->path, options);
		printf(" ");
		print_owner(file->path, options);
		printf(" ");
		print_group(file->path, options);
		printf(" ");
		print_size(file->path, options);
		printf(" %s\n", file->filename);
	}
}
