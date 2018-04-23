/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_longlong.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 19:26:56 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/23 13:22:11 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long		ft_atoi_longlong(const char *str)
{
	unsigned long long	ret;

	ret = 0;
	while (*str == ' ' || *str == '\n' || *str == '\v' || *str == '\f'
			|| *str == '\r' || *str == '\t')
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		ret *= 10;
		ret += *str - '0';
		str++;
	}
	return (ret);
}
