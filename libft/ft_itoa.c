/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 09:53:42 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/05 10:39:07 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	size_t			len;
	unsigned int	nbr;
	char			*ret;

	len = ft_get_nbr_len(n);
	nbr = n;
	if (n < 0)
	{
		nbr = -n;
		len++;
	}
	if (!(ret = ft_strnew(len)))
		return (NULL);
	while (nbr)
	{
		ret[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (n < 0)
		ret[0] = '-';
	if (n == 0)
		ret[0] = '0';
	return (ret);
}
