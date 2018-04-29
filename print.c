/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 19:02:52 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/29 13:52:31 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_gaps(int offset)
{
	int i;

	i = 0;
	while (i < offset)
	{
		ft_putchar(' ');
		i++;
	}
}

void		print_str(const char *str, int offset, t_bool right, t_bool space)
{
	if (!str)
		return ;
	offset -= ft_strlen(str);
	if (right)
		print_gaps(offset);
	ft_putstr(str);
	if (!right)
		print_gaps(offset);
	if (space)
		ft_putchar(' ');
}

void		print_nbr(long long nbr, int offset, t_bool right, t_bool space)
{
	offset -= ft_get_nbr_len(nbr);
	if (right)
		print_gaps(offset);
	ft_putnbr(nbr);
	if (!right)
		print_gaps(offset);
	if (space)
		ft_putchar(' ');
}
