/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_conn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:10:26 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/23 14:10:28 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strjoin_conn(char const *s1, char const *s2, const char c)
{
	size_t		i;
	size_t		x;
	char		*ret;
	char		*cpy;

	i = (s1 ? ft_strlen(s1) : 0);
	x = (s2 ? ft_strlen(s2) : 0);
	ret = (char *)malloc(sizeof(char) * (i + x + 2));
	if (!ret)
		return (NULL);
	cpy = ret;
	if (s1)
		while (*s1)
			*(cpy++) = *(s1++);
	*(cpy++) = c;
	if (s2)
		while (*s2)
			*(cpy++) = *(s2++);
	*cpy = '\0';
	return (ret);
}
