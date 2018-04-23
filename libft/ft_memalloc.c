/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:42:35 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/11 14:46:33 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	void	*ret;
	void	*cpy;
	size_t	i;

	i = 0;
	ret = (void *)malloc(sizeof(void) * size);
	if (!ret)
		return (NULL);
	cpy = ret;
	while (i < size)
	{
		*(void **)cpy = NULL;
		cpy++;
		i++;
	}
	return (ret);
}
