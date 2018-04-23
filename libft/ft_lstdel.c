/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:24:04 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/05 13:37:11 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*ptr;
	t_list		*next;

	if (!alst || !del)
		return ;
	next = *alst;
	while (next)
	{
		ptr = next;
		next = next->next;
		ft_lstdelone(&ptr, del);
	}
	*alst = NULL;
}
