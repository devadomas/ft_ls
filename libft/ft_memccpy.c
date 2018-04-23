/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:15:16 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/03 16:43:50 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*o_dst;
	char		*o_src;

	i = 0;
	o_dst = dst;
	o_src = (void *)src;
	while (i < n)
	{
		if (*(unsigned char *)o_src == (unsigned char)c)
		{
			*(unsigned char *)(o_dst++) = (unsigned char)c;
			return (o_dst);
		}
		*(unsigned char *)(o_dst++) = *(unsigned char *)(o_src++);
		i++;
	}
	return (NULL);
}
