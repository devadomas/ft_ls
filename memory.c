/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 09:30:49 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/24 09:35:30 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

void		clean_memory(t_file *files, t_opt *options)
{
	t_file *file;

	if (options)
		free(options);
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
