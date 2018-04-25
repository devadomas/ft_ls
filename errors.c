/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 09:55:40 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/25 15:07:37 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

#include <stdio.h>

void		print_error(const char *filename)
{
	printf("ft_ls: %s: No such file or directory\n", filename);
}

void		print_usage(const char option, t_opt *options)
{
	printf("ft_ls: illegal option -- %c\n", option);
	printf("usage: ft_ls [-%s] [file ...]\n", options->charset);
	free(options);
	exit(1);
}
