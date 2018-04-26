/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 09:55:40 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/26 12:12:37 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

#include <stdio.h>

void		print_error(const char *filename)
{
	char		*error;

	error = strerror(errno);
	//perror(error);
	//printf("%d <-> %s\n", errno, error);
	if (errno != 20)
		printf("ft_ls: %s: %s\n", filename, error);
}

void		print_usage(const char option, t_opt *options)
{
	printf("ft_ls: illegal option -- %c\n", option);
	printf("usage: ft_ls [-%s] [file ...]\n", options->charset);
	free(options);
	exit(1);
}
