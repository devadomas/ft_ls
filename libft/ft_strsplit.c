/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 20:36:41 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/11 14:49:00 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t		ft_get_wrd_count(char const *s, char c)
{
	size_t	counter;
	size_t	state;

	if (!s)
		return (0);
	counter = 0;
	state = 0;
	while (*s)
	{
		if (*s == c)
			state = 0;
		else if (!state)
		{
			state = 1;
			counter++;
		}
		s++;
	}
	return (counter);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**ret;
	size_t		i;
	size_t		state;

	if (!s)
		return (NULL);
	i = ft_get_wrd_count(s, c);
	if (!(ret = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	state = 0;
	while (*s)
	{
		if (*s == c)
			state = 0;
		else if (!state)
		{
			if (!(ret[i] = ft_get_next_word(s, c)))
				return (NULL);
			i += ++state;
		}
		s++;
	}
	ret[i] = NULL;
	return (ret);
}
