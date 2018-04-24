/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offsets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:27:16 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/24 22:23:45 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	add_total(t_file *list, t_opt *options)
{
	if (is_file_hidden(list->filename) && !options->include_hidden)
		return ;
	options->total += (list->sb)->st_blocks;
}

void		load_offsets(t_file *list, t_opt *options)
{
	int				len;
	struct stat		*sb;

	while (list)
	{
		sb = list->sb;
		if (sb)
		{
			len = ft_get_nbr_len(sb->st_nlink);
			if (len > options->hlink_offset)
				options->hlink_offset = len;
			len = ft_strlen(list->uname);
			if (len > options->owner_offset)
				options->owner_offset = len;
			len = ft_strlen(list->gname);
			if (len > options->group_offset)
				options->group_offset = len;
			len = ft_get_nbr_len(sb->st_size);
			if (len > options->size_offset)
				options->size_offset = len;
			len = ft_strlen(list->filename);
			if (!(is_file_hidden(list->filename) && !(options->include_hidden)))
				if (len > options->title_offset)
					options->title_offset = len;
			add_total(list, options);
		}
		list = list->next;
	}
}
