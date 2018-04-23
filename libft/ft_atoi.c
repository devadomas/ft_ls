/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:18:03 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/05 14:00:16 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long	ret;
	int			multiply;

	ret = 0;
	multiply = 1;
	while (*str == ' ' || *str == '\n' || *str == '\v' || *str == '\f'
			|| *str == '\r' || *str == '\t')
		str++;
	if (*str == '-')
		multiply = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		ret *= 10;
		ret += *str - '0';
		str++;
	}
	return (ret * multiply);
}
