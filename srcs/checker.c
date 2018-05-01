/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:20:17 by azaliaus          #+#    #+#             */
/*   Updated: 2018/05/01 07:56:37 by azaliaus         ###   ########.fr       */
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

void		check_args(int begin, int ac, char **av)
{
	int i;

	i = begin;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			print_arg_empty();
		i++;
	}
}

void		precheck_args(int begin, int ac, char **av)
{
	DIR		*dir;

	while (begin < ac)
	{
		dir = opendir(av[begin]);
		if (!dir && (lstat(av[begin], NULL) != 0))
		{
			if (errno == ENOENT)
				print_error(av[begin]);
		}
		if (dir)
			closedir(dir);
		begin++;
	}
}
