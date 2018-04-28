/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 09:55:40 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/28 19:57:43 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

#include <stdio.h>

void		print_error(const char *filename)
{
	char		*error;

	error = strerror(errno);
	if (errno != 20)
	{
		// printf("ls: %s: %s\n", filename, error);
		ft_putstr("ls: ");
		ft_putstr(filename);
		ft_putstr(": ");
		ft_putstr(error);
		ft_putchar('\n');
	}
}

void		print_usage(const char option, t_opt *options)
{
	// printf("ft_ls: illegal option -- %c\n", option);
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(option);
	ft_putchar('\n');
	// printf("usage: ft_ls [-%s] [file ...]\n", options->charset);
	ft_putstr("usage: ft_ls [-");
	ft_putstr(options->charset);
	ft_putstr("] [file ...]\n");
	free(options);
	exit(1);
}
