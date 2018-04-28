/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:19:44 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/28 15:30:15 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#include <stdio.h>

void		print_header(t_opt *options, const char *filename, const char *path,
		int root)
{
	printf((options->count ? "\n" : ""));
	if (options->total_files > 0 || (options->rec && options->count))
		printf("%s:\n", (options->rec && !root ? path : filename));
}

void		sort_files(t_opt *options, t_file **files)
{
	if (options->sorted_t)
		sort_files_bytime(files);
	else
		sort_files_byname(files);
}
