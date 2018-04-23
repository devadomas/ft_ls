/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 10:37:38 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/05 10:38:49 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_get_nbr_len(int n)
{
	size_t			ret;
	unsigned int	nbr;

	ret = 1;
	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	while (nbr /= 10)
		ret++;
	return (ret);
}
