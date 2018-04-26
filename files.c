/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 11:01:13 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/26 16:58:53 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

static char	*get_symlink(const char *path, t_opt *options)
{
	struct stat		sb;
	char			*ret;
	int				len;

	if (lstat(path, &sb) == 0)
	{
		ret = (char *)malloc(sizeof(char) * LINK_BUFF + 1);
		if (!ret)
			return (NULL);
		if ((len = readlink(path, ret, LINK_BUFF + 1)) == -1)
		{
			free(ret);
			return (NULL);
		}
		ret[len] = '\0';
		if (stat(ret, &sb) == 0)
		{
			options->total += sb.st_blocks;
			return (ret);
		}
		free(ret);
	}
	return (NULL);
}

t_file		*init_file(const char *filename, const char *path, t_opt *options)
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
	if (lstat(ret->path, sb) == 0)
	{
		ret->sb = sb;
		if (sb->st_mode)
			ret->is_dir = (S_ISDIR(sb->st_mode) ? 1 : 0);
		usr = getpwuid(sb->st_uid);
		grp = getgrgid(sb->st_gid);
		ret->gname = (grp ? ft_strdup(grp->gr_name) :
				ft_convert_to_base(sb->st_gid, 10));
		ret->uname = (usr ? ft_strdup(usr->pw_name) :
				ft_convert_to_base(sb->st_uid, 10));
		ret->symlink = get_symlink(ret->path, options);
	}
	else
	{
		free(ret);
		return (NULL);
	}
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
