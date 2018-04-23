/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:02:24 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/05 11:14:14 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*ptr;

	ptr = (t_list *)ft_memalloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->next = NULL;
	if (!content)
	{
		ptr->content = NULL;
		ptr->content_size = 0;
		return (ptr);
	}
	ptr->content_size = content_size;
	ptr->content = ft_memalloc(content_size);
	if (!ptr->content)
		return (NULL);
	ft_memcpy(ptr->content, content, content_size);
	return (ptr);
}
