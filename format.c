/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:11:39 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/23 18:54:01 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

#include <stdio.h>

static void		print_permissions(t_file *file)
{
	struct stat		*sb;

	if (!(file->sb))
	{
		printf("----------");
		return ;
	}
	sb = file->sb;
	printf((S_ISDIR(sb->st_mode)) ? "d" : "-");
	printf((sb->st_mode & S_IRUSR) ? "r" : "-");
	printf((sb->st_mode & S_IWUSR) ? "w" : "-");
	printf((sb->st_mode & S_IXUSR) ? "x" : "-");
	printf((sb->st_mode & S_IRGRP) ? "r" : "-");
	printf((sb->st_mode & S_IWGRP) ? "w" : "-");
	printf((sb->st_mode & S_IXGRP) ? "x" : "-");
	printf((sb->st_mode & S_IROTH) ? "r" : "-");
	printf((sb->st_mode & S_IWOTH) ? "w" : "-");
	printf((sb->st_mode & S_IXOTH) ? "x" : "-");
	printf(" "); // don't know if is needed for @ tag
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
	struct passwd 	*usr;

	if (!(file->sb))
	{
		printf("%*s", options->owner_offset, "unknown"); // make sure about this one
		return ;
	}
	usr = getpwuid((file->sb)->st_uid);
	if (!usr)
		return ;
	printf("%*s", options->owner_offset, usr->pw_name);
	//free(usr);
}

static void		print_group(t_file *file, t_opt *options)
{
	struct group	*usr;

	if (!(file->sb))
	{
		printf("%*s", options->group_offset + 1, "unknown");
		// make sure about this one
		return ;
	}
	usr = getgrgid((file->sb)->st_gid);
	if (!usr)
		return ;
	printf("%*s", options->group_offset + 1, usr->gr_name);
	//free(usr);
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
	time_t			modified;

	(void)options;
	(void)modified;
	if (!(file->sb))
	{
		printf("XXX XX XX:XX");//to fix
		return ;
	}
	// typed here
}

void			format_output(t_file *file, t_opt *options)
{
	if (is_file_hidden(file->filename) && !(options->include_hidden))
		return ;
	if (options->long_list) /* formatting -l option */
	{
		print_permissions(file);
		printf(" ");
		print_hard_links(file, options);
		printf(" ");
		print_owner(file, options);
		printf(" ");
		print_group(file, options);
		printf(" ");
		print_size(file, options);
		printf(" ");
		print_date(file, options);

		printf(" %s\n", file->filename);
	}
}
