/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:06:27 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/03 15:43:45 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char		*str;
	size_t		i;

	i = 0;
	str = b;
	while (i < len)
	{
		*str = (unsigned char)c;
		str++;
		i++;
	}
	return (b);
}
