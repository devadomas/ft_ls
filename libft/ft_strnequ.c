/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:58:01 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/05 13:35:12 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	i = 1;
	if (!s1 || !s2)
		return (0);
	if ((!*s1 && !*s2) || (n == 0))
		return (1);
	if (!*s1 || !*s2)
		return (0);
	while (*s1 && *s2 && i < n)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
		i++;
	}
	if (i == n && *s1 == *s2)
		return (1);
	if (*s1 || *s2)
		return (0);
	return (1);
}
