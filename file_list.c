/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:34:41 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/23 16:17:21 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		file_list_len(t_file *list)
{
	int ret;

	ret = 0;
	while (list)
	{
		ret++;
		list = list->next;
	}
	return (ret);
}

static void		swap_node(t_file **list, t_file **prev, t_file **curr,
		t_file **next)
{
	if (*curr == *list)
		*list = *next;
	else
		(*prev)->next = (*next);
	(*curr)->next = (*next)->next;
	(*next)->next = (*curr);
	(*prev) = (*next);
	(*next) = (*curr)->next;
}

void			sort_files_byname(t_file **files, t_bool reverse)
{
	(void)reverse;
	int			i;
	t_file		*prev;
	t_file		*curr;
	t_file		*next;
	int			len;

	if (!(*files))
		return ;
	i = -1;
	len = file_list_len(*files);
	while (++i < len)
	{
		prev = 0;
		curr = *files;
		next = curr->next;
		while (next)
		{
			if (ft_strcmp(curr->filename, next->filename) > 0)
				swap_node(files, &prev, &curr, &next);
			else
			{
				prev = curr;
				curr = curr->next;
				next = curr->next;
			}
		}
	}
}
