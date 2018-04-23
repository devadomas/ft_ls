/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:41:43 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/04 13:31:10 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cpy;
	char	*last;

	last = NULL;
	cpy = (char *)s;
	while (*cpy)
	{
		if (*cpy == (char)c)
			last = cpy;
		cpy++;
	}
	if (last)
		return (last);
	if ((char)c == '\0')
		return (cpy);
	return (NULL);
}
