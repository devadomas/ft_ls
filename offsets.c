/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offsets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:27:16 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/28 18:48:56 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	add_total(t_file *list, t_opt *options)
{
	if (is_file_hidden(list->filename) && !options->include_hidden)
		return ;
	options->total += (list->sb)->st_blocks;
}

void		load_offset(t_file *file, t_opt *options)
{
	int				len;
	struct stat		*sb;

	if (!options)
		return ;
	sb = file->sb;
	if (sb &&
			!(is_file_hidden(file->filename) && !(options->include_hidden)))
	{
		len = ft_get_nbr_len(sb->st_nlink);
		if (len > options->hlink_offset)
			options->hlink_offset = len;
		len = (file->uname ? ft_strlen(file->uname) : 0);
		if (len > options->owner_offset)
			options->owner_offset = len;
		len = (file->gname ? ft_strlen(file->gname) : 0);
		if (len > options->group_offset)
			options->group_offset = len;
		len = ft_get_nbr_len(sb->st_size);
		if (len > options->size_offset)
			options->size_offset = len;
		len = ft_strlen(file->filename);
		if (!(is_file_hidden(file->filename) && !(options->include_hidden)))
			if (len > options->title_offset)
				options->title_offset = len;
		add_total(file, options);
	}
}
