/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr_len_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 11:17:56 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/23 11:18:48 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_nbr_len_unsigned(unsigned long long n)
{
	int				ret;

	ret = 1;
	while (n /= 10)
		ret++;
	return (ret);
}
