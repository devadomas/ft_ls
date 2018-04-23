/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:24:26 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/03 19:39:52 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	*cpy;

	cpy = (char *)s;
	while (*cpy)
	{
		if (*cpy == (char)c)
			return (cpy);
		cpy++;
	}
	if ((char)c == '\0')
		return (cpy);
	return (NULL);
}
