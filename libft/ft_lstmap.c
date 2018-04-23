/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:46:32 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/05 11:52:05 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*begin;
	t_list		*tmp;

	if (!lst || !f)
		return (NULL);
	begin = (*f)(lst);
	if (!begin)
		return (NULL);
	tmp = begin;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = (*f)(lst);
		if (!tmp->next)
			return (NULL);
		tmp = tmp->next;
	}
	return (begin);
}
