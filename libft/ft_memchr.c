/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:57:03 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/03 18:00:57 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*cpy;

	i = 0;
	cpy = (void *)s;
	while (i < n)
	{
		if (*(unsigned char *)(cpy) == (unsigned char)c)
			return (cpy);
		cpy++;
		i++;
	}
	return (NULL);
}
