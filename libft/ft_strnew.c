/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:09:06 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/04 14:12:18 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*ptr;
	char	*cpy;
	size_t	i;

	i = 0;
	ptr = (char *)ft_memalloc(size + 1);
	if (!ptr)
		return (NULL);
	cpy = ptr;
	while (i++ <= size)
	{
		*cpy = '\0';
		cpy++;
	}
	return (ptr);
}
