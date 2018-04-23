/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 19:31:22 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/21 19:32:17 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int nbr, int times)
{
	int		ret;
	int		i;

	i = 1;
	ret = nbr;
	if (times == 0)
		return (1);
	while (i++ < times)
		ret *= nbr;
	return (ret);
}
