/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_word.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 09:22:43 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/11 14:49:13 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_get_next_word(char const *s, char c)
{
	size_t		size;
	char		*ret;

	size = 0;
	if (!s)
		return (NULL);
	while (s[size] != c && s[size])
		size++;
	if (!(ret = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	size = 0;
	while (*s != c && *s)
		ret[size++] = *(s++);
	ret[size] = '\0';
	return (ret);
}
