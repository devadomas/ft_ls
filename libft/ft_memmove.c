/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:44:36 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/04 19:23:01 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*o_src;
	unsigned char	*o_dst;

	o_src = (unsigned char *)src;
	o_dst = (unsigned char *)dst;
	if (o_src > o_dst)
		ft_memcpy(dst, src, len);
	else
	{
		while (len--)
			o_dst[len] = o_src[len];
	}
	return (dst);
}
