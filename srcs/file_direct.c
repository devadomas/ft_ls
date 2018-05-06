/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_direct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 10:44:18 by azaliaus          #+#    #+#             */
/*   Updated: 2018/05/06 18:49:45 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#include <stdlib.h>

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
	t_file		*last;
	DIR			*dir;

	files = NULL;
	last = files;
	while (begin < ac)
	{
		dir = opendir(av[begin]);
		if (is_file(av[begin]) && !(dir && !(options->long_list)))
		{
			options->count++;
			file_push_back(&files, init_file(av[begin],
						(av[begin][0] != '/' ? "." : "")), &last, options);
		}
		if (dir)
			closedir(dir);
		begin++;
	}
	if (!files)
		return ;
	sort_files(options, &files);
	reverse_files_list(&files, options);
	format_output(files, options, FALSE);
	clean_files_memory(files, options);
}
