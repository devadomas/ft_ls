/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 21:11:48 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/25 21:33:56 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_floor(float nbr)
{
	int			ret;
	float		calc;

	calc = nbr - (int)nbr;
	calc *= 10;
	ret = (int)calc;
	return (ret >= 5 ? (int)nbr + 1 : (int)nbr);
}
