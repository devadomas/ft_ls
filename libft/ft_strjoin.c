/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:13:34 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/11 14:47:45 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		x;
	char		*ret;
	char		*cpy;

	i = (s1 ? ft_strlen(s1) : 0);
	x = (s2 ? ft_strlen(s2) : 0);
	ret = (char *)malloc(sizeof(char) * (i + x + 1));
	if (!ret)
		return (NULL);
	cpy = ret;
	if (s1)
		while (*s1)
			*(cpy++) = *(s1++);
	if (s2)
		while (*s2)
			*(cpy++) = *(s2++);
	*cpy = '\0';
	return (ret);
}
