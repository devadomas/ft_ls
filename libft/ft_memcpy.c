/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:01:57 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/03 16:14:09 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*n_dst;
	char		*o_src;

	i = 0;
	n_dst = dst;
	o_src = (void *)src;
	while (i < n)
	{
		*(n_dst++) = *(o_src++);
		i++;
	}
	return (dst);
}
