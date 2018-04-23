/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 11:01:13 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/19 20:42:00 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

#include <stdio.h>

t_file		*init_file(char *filename)
{
	t_file		*ret;
	struct stat	sb;

	ret = (t_file *)malloc(sizeof(t_file));
	if (!ret)
		return (NULL);
	ret->filename = filename;
	/*
	 * If it's dir
	 * */
	if (stat(filename, &sb) == 0)
	{
		if (sb.st_mode)
			ret->is_dir = (S_ISDIR(sb.st_mode) ? 1 : 0);
	}
	else
	{
		ret->is_dir = 0;
		return (NULL); /* massive memory leak */
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
