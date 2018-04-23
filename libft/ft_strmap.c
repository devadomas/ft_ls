/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:41:15 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/11 14:47:13 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	char		*ptr;
	char		*cpy;
	size_t		size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * size + 1);
	if (!ptr)
		return (NULL);
	cpy = ptr;
	while (*s)
	{
		*cpy = f(*s);
		cpy++;
		s++;
	}
	*cpy = '\0';
	return (ptr);
}
