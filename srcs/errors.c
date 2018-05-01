/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 09:55:40 by azaliaus          #+#    #+#             */
/*   Updated: 2018/05/01 07:55:22 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

void		print_error(const char *filename)
{
	char		*error;

	error = strerror(errno);
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(error, 2);
		ft_putchar_fd('\n', 2);
}

void		print_usage(const char option, t_opt *options)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(option, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: ft_ls [-", 2);
	ft_putstr_fd(options->charset, 2);
	ft_putstr_fd("] [file ...]\n", 2);
	free(options);
	exit(1);
}

void		print_arg_empty(void)
{
	ft_putstr_fd("ls: fts_open: No such file or directory\n", 2);
	exit(1);
}
