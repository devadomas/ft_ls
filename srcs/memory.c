/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 09:30:49 by azaliaus          #+#    #+#             */
/*   Updated: 2018/05/01 15:24:22 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

void		clean_files_memory(t_file *files, t_opt *options)
{
	t_file *file;

	if (options)
	{
		options->hlink_offset = 0;
		options->owner_offset = 0;
		options->group_offset = 0;
		options->size_offset = 0;
		options->title_offset = 0;
		options->total = 0;
	}
	while (files)
	{
		file = files;
		files = files->next;
		free(file->filename);
		free(file->path);
		free(file->uname);
		free(file->gname);
		free(file->sb);
		free(file->symlink);
		free(file);
	}
}

void		clean_options_memory(t_opt *options)
{
	if (!options)
		return ;
	free(options->charset);
	free(options->window);
	free(options);
}

void		clean_options(t_opt *options)
{
	if (!options)
		return ;
	options->hlink_offset = 0;
	options->owner_offset = 0;
	options->group_offset = 0;
	options->size_offset = 0;
	options->title_offset = 0;
	options->total = 0;
}

void		clear_failed_file(t_file *file)
{
	if (!file)
		return ;
	if (file->filename)
		free(file->filename);
	if (file->path)
		free(file->path);
	if (file->sb)
		free(file->sb);
	free(file);
}
