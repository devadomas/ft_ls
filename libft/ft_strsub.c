/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:26:58 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/11 14:47:35 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	char		*cpy;

	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr || !s)
		return (NULL);
	cpy = ptr;
	while (start)
	{
		start--;
		s++;
	}
	while (len)
	{
		*cpy = *s;
		cpy++;
		s++;
		len--;
	}
	*cpy = '\0';
	return (ptr);
}
