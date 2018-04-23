/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:03:16 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/11 14:47:24 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	char			*cpy;
	size_t			size;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * size + 1);
	if (!ptr)
		return (NULL);
	cpy = ptr;
	while (*s)
	{
		*cpy = f(i, *s);
		cpy++;
		s++;
		i++;
	}
	*cpy = '\0';
	return (ptr);
}
