/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 09:30:49 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/24 21:36:59 by azaliaus         ###   ########.fr       */
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
		free(files->filename);
		free(files->path);
		free(files->sb);
		free(files->gname);
		free(files->uname);
		file = files;
		files = files->next;
		free(file);
	}
}

void		clean_options_memory(t_opt *options)
{
	if (!options)
		return ;
	free(options->window);
	free(options);
}
