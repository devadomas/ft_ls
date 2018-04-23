/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 09:55:40 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/16 09:59:39 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#include <stdio.h>

void		print_error(char *filename)
{
	printf("ft_ls: %s: No such file or directory\n", filename);
}
