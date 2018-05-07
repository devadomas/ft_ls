/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 11:01:13 by azaliaus          #+#    #+#             */
/*   Updated: 2018/05/06 21:18:29 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include <unistd.h>

static char		*get_symlink(const char *path)
{
	char			*ret;
	int				len;

	if (!(ret = (char *)malloc(sizeof(char) * LINK_BUFF + 1)))
		return (NULL);
	if ((len = readlink(path, ret, LINK_BUFF + 1)) == -1)
	{
		free(ret);
		return (NULL);
	}
	ret[len] = '\0';
	return (ret);
}

static t_bool	init_vars(const char *filename, const char *path, t_file **lst)
{
	if (!(*lst))
		return (FALSE);
	if (!((*lst)->filename = ft_strdup(filename)))
	{
		clear_failed_file(*lst);
		return (FALSE);
	}
	if (!((*lst)->path = init_path(path, filename)))
	{
		clear_failed_file(*lst);
		return (FALSE);
	}
	if (!((*lst)->sb = (struct stat *)malloc(sizeof(struct stat))))
	{
		clear_failed_file(*lst);
		return (FALSE);
	}
	if (lstat((*lst)->path, (*lst)->sb) != 0)
	{
		clear_failed_file(*lst);
		return (FALSE);
	}
	return (TRUE);
}

t_file			*init_file(const char *filename, const char *path)
{
	t_file			*ret;
	struct stat		*sb;
	struct group	*grp;
	struct passwd	*usr;

	if (!(ret = (t_file *)malloc(sizeof(t_file))) ||
		!init_vars(filename, path, &ret))
		return (NULL);
	sb = ret->sb;
	ret->symlink = get_symlink(ret->path);
	if (sb->st_mode)
		ret->is_dir = (S_ISDIR(sb->st_mode) ? 1 : 0);
	if (!(ret->symlink))
		stat(ret->path, sb);
	usr = getpwuid(sb->st_uid);
	grp = getgrgid(sb->st_gid);
	ret->uname = (usr ? ft_strdup(usr->pw_name) : ft_itoa(sb->st_uid));
	ret->gname = (grp ? ft_strdup(grp->gr_name) : ft_itoa(sb->st_gid));
	return (ret);
}

void			file_push_back(t_file **list, t_file *file, t_file **lst,
		t_opt *options)
{
	if (!file)
		return ;
	file->next = NULL;
	if (!(*list))
	{
		*list = file;
		*lst = file;
	}
	else
	{
		(*lst)->next = file;
		*lst = file;
	}
	load_offset(file, options);
}

t_bool			is_file_hidden(const char *filename)
{
	if (filename)
		if (*filename == '.')
			return (TRUE);
	return (FALSE);
}
