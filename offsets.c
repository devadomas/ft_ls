/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offsets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:27:16 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/23 19:07:10 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		load_offsets(t_file *list, t_opt *options)
{
	int				hlink_offset;
	struct stat		*sb;

	hlink_offset = 0;
	while (list)
	{
		sb = list->sb;
		if (sb)
		{
			if (ft_get_nbr_len(sb->st_nlink) > hlink_offset)
				hlink_offset = ft_get_nbr_len(sb->st_nlink);
			if (ft_strlen(list->uname) > (size_t)options->owner_offset)
				options->owner_offset = ft_strlen(list->uname);
			if (ft_strlen(list->gname) > (size_t)options->group_offset)
				options->group_offset = ft_strlen(list->gname);
			if (ft_get_nbr_len(sb->st_size) > options->size_offset)
				options->size_offset = ft_get_nbr_len(sb->st_size);
		}
		list = list->next;
	}
	options->hlink_offset = hlink_offset;
}
