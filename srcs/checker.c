/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:20:17 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/30 17:01:41 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			set_dup_arg(t_opt *options, char arg)
{
	if (arg == '1')
		options->long_list = 0;
	if (arg == 'l')
		options->one = 0;
	if (arg == 'f')
		options->include_hidden = 1;
	if (arg == 'g')
		options->long_list = 1;
	if (arg == 'o')
		options->long_list = 1;
	return (1);
}
