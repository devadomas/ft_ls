/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 18:17:57 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/30 18:17:57 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_ls(int ac, char **av)
{
	t_opt	*options;
	int		start_point;

	options = init_opt();
	start_point = load_options(options, ac, av);
	sort_arguments(start_point, ac, av);
	if (start_point == ac)
		read_dir(".", ".", options, 1);
	else
	{
		process_files(start_point, ac, av, options);
		process_dirs(start_point, ac, av, options);
	}
	clean_options_memory(options);
}
