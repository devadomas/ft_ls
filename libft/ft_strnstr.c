/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:03:41 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/04 11:03:42 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		x;

	i = 0;
	if (!*haystack && !*needle)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		x = 0;
		while (needle[x] && haystack[i + x] && needle[x] == haystack[i + x])
			x++;
		if (needle[x] == '\0' && (i + x) <= len)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
