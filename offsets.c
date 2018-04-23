/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offsets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:27:16 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/23 16:57:44 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		load_offsets(t_file *list, t_opt *options)
{
	int				hlink_offset;
	struct stat		sb;
	struct passwd	*usr;
	struct group	*grp;

	hlink_offset = 0;
	while (list)
	{
		if (stat(list->path, &sb) >= 0)
		{
			if (ft_get_nbr_len(sb.st_nlink) > hlink_offset)
				hlink_offset = ft_get_nbr_len(sb.st_nlink);
			usr = getpwuid(sb.st_uid);
			if (ft_strlen(usr->pw_name) > (size_t)options->owner_offset)
				options->owner_offset = ft_strlen(usr->pw_name);
			grp = getgrgid(sb.st_gid);
			if (ft_strlen(grp->gr_name) > (size_t)options->group_offset)
				options->group_offset = ft_strlen(grp->gr_name);
			if (ft_get_nbr_len(sb.st_size) > options->size_offset)
				options->size_offset = ft_get_nbr_len(sb.st_size);
		}
		list = list->next;
	}
	options->hlink_offset = hlink_offset;
}
