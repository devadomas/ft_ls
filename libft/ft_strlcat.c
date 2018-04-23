/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:12:09 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/03 19:23:01 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		x;
	size_t		dlen;
	size_t		slen;

	dlen = ft_strlen(dst);
	i = dlen;
	x = 0;
	slen = ft_strlen(src);
	if (size < dlen + 1)
		return (slen + size);
	if (size > dlen + 1)
	{
		while (i < size - 1)
			*(dst + i++) = *(src + x++);
		*(dst + i) = '\0';
	}
	return (slen + dlen);
}
