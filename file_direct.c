/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_direct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 10:44:18 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/27 13:59:51 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#include <stdio.h>

t_bool		is_file(const char *path)
{
	struct stat		sb;

	if (!path)
		return (FALSE);
	if (lstat(path, &sb) == 0)
		if (!(S_ISDIR(sb.st_mode)))
			return (TRUE);
	return (FALSE);
}

void		process_files(int begin, int ac, char **av, t_opt *options)
{
	t_file		*files;

	files = NULL;
	while (begin < ac)
	{
		if (is_file(av[begin]))
		{
			options->count++;
			file_push(&files, init_file(av[begin],
					   (av[begin][0] != '/' ? "." : ""),
					   	options));
		}
		begin++;
	}
	if (!files)
		return ;
	if (options->sorted_t)
		sort_files_bytime(&files);
	else
		sort_files_byname(&files, (options->reversed ? TRUE : FALSE));
	if (options->reversed)
		reverse_files_list(&files);
	load_offsets(files, options);
	format_output(files, options, FALSE);
	clean_files_memory(files, options);
}
