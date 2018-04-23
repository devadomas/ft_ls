/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:11:39 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/23 19:50:25 by azaliaus         ###   ########.fr       */
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
	if (!(file->uname))
	{
		printf("%*s", options->owner_offset, "unknown"); // make sure about this one
		return ;
	}
	printf("%*s", options->owner_offset, file->uname);
	//free(usr);
}

static void		print_group(t_file *file, t_opt *options)
{
	if (!(file->gname))
	{
		printf("%*s", options->group_offset + 1, "unknown");
		// make sure about this one
		return ;
	}
	printf("%*s", options->group_offset + 1, file->gname);
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
	char			*time_str;
	char			*formatted;

	(void)options;
	if (!(file->sb))
	{
		printf("XXX XX XX:XX");//to fix
		return ;
	}
	time_str = ctime(&(file->sb)->st_mtime);
	formatted = ft_strsub(time_str, 4, 12);
	printf("%s", formatted);
	free(formatted);
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
