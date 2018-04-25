/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:34:41 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/25 11:00:18 by azaliaus         ###   ########.fr       */
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

int				get_file_list_len(t_file *files, int hidden)
{
	int i;

	i = 0;
	while (files)
	{
		if (!(is_file_hidden(files->filename) && !(hidden)))
			i++;
		files = files->next;
	}
	return (i);
}

t_file			*get_nth_file(t_file *files, unsigned int nth, int hidden)
{
	unsigned int		i;

	i = -1;
	while (files)
	{
		if (!(is_file_hidden(files->filename) && !(hidden)))
			i++;
		if (i == nth)
			return (files);
		files = files->next;
	}
	return (NULL);
}
