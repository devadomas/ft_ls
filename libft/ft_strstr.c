/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 10:40:57 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/04 11:02:21 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;
	size_t		x;

	i = 0;
	if (!*haystack && !*needle)
		return ((char *)haystack);
	while (haystack[i])
	{
		x = 0;
		while (needle[x] && haystack[i + x] && needle[x] == haystack[i + x])
			x++;
		if (needle[x] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
