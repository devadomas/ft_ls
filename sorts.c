/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 14:32:07 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/28 16:49:48 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

void			sort_arguments(int begin, int ac, char **av)
{
	int			i;
	int			j;
	char		*tmp;

	i = begin;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_strcmp(av[i], av[j]) > 0)
			{
				tmp = av[i];
				av[i] = av[j];
				av[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void		iterate_flist(t_file **prev, t_file **curr, t_file **next)
{
	*prev = *curr;
	*curr = (*curr)->next;
	*next = (*curr)->next;
}

void			sort_files_byname(t_file **files)
{
	int			i;
	t_file		*prev;
	t_file		*curr;
	t_file		*next;
	int			len;

	if (!(*files))
		return ;
	i = -1;
	len = get_file_list_len(*files, TRUE);
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
				iterate_flist(&prev, &curr, &next);
		}
	}
}

void			sort_files_bytime(t_file **files)
{
	int			i;
	t_file		*prev;
	t_file		*curr;
	t_file		*next;
	int			len;

	if (!(*files))
		return ;
	i = -1;
	len = get_file_list_len(*files, TRUE);
	while (++i < len)
	{
		prev = 0;
		curr = *files;
		next = curr->next;
		while (next)
		{
			if ((curr->sb)->st_mtime < (next->sb)->st_mtime ||
					((curr->sb)->st_mtime == (next->sb)->st_mtime &&
					ft_strcmp(curr->filename, next->filename) > 0))
				swap_node(files, &prev, &curr, &next);
			else
				iterate_flist(&prev, &curr, &next);
		}
	}
}
