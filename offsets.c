/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offsets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:27:16 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/26 13:48:49 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>

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

	if (!options)
		return ;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, options->window);
	while (list)
	{
		sb = list->sb;
		if (sb &&
				!(is_file_hidden(list->filename) && !(options->include_hidden)))
		{
			len = ft_get_nbr_len(sb->st_nlink);
			if (len > options->hlink_offset)
				options->hlink_offset = len;
			len = (list->uname ? ft_strlen(list->uname) : 0);
			if (len > options->owner_offset)
				options->owner_offset = len;
			len = (list->gname ? ft_strlen(list->gname) : 0);
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
