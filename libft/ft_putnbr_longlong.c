/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_longlong.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:56:52 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/22 16:01:57 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_longlong(long long n)
{
	if (n == -9223372036854775807)
	{
		ft_putchar('-');
		ft_putnbr_longlong(9223372036854775807 / 10);
		ft_putnbr_longlong(9223372036854775807 % 10);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr_longlong(-n);
	}
	else if (n >= 0 && n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr_longlong(n / 10);
		ft_putnbr_longlong(n % 10);
	}
}
