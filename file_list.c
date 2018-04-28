/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:34:41 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/28 14:38:20 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			reverse_files_list(t_file **files)
{
	t_file		*curr;
	t_file		*prev;
	t_file		*next;

	prev = NULL;
	next = *files;
	if (!next)
		return ;
	while (next)
	{
		curr = next;
		next = curr->next;
		curr->next = prev;
		prev = curr;
	}
	*files = curr;
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
