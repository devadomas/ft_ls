/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 11:01:13 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/23 19:42:41 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

#include <stdio.h>

t_file		*init_file(const char *filename, const char *path)
{
	t_file			*ret;
	struct stat		*sb;
	struct passwd	*usr;
	struct group	*grp;

	ret = (t_file *)malloc(sizeof(t_file));
	if (!ret || !(ret->filename = ft_strdup(filename)) ||
			!(ret->path = ft_strjoin_conn(path, filename, '/')) ||
			!(sb = (struct stat *)malloc(sizeof(struct stat))))
		return (NULL);
	if (stat(ret->path, sb) == 0)
	{
		ret->sb = sb;
		if (sb->st_mode)
			ret->is_dir = (S_ISDIR(sb->st_mode) ? 1 : 0);
		usr = getpwuid(sb->st_uid);
		grp = getgrgid(sb->st_gid);
		ret->gname = ft_strdup(grp->gr_name);
		ret->uname = ft_strdup(usr->pw_name);
	}
	else
		ret->is_dir = 0;
	ret->next = NULL;
	return (ret);
}

void		file_push(t_file **list, t_file *file)
{
	t_file		*cpy;

	cpy = *list;
	if (!cpy)
		*list = file;
	else
	{
		while (cpy->next)
			cpy = cpy->next;
		cpy->next = file;
	}
}

t_bool		is_file_hidden(const char *filename)
{
	if (filename)
		if (*filename == '.')
			return (TRUE);
	return (FALSE);
}
