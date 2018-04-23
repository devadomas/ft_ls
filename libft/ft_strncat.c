/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:06:58 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/03 19:10:55 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*dst;
	char	*src;
	size_t	i;

	i = 0;
	dst = s1;
	src = (char *)s2;
	while (*dst)
		dst++;
	while (i < n && *src)
	{
		*(dst++) = *(src++);
		i++;
	}
	*dst = '\0';
	return (s1);
}
