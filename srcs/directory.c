/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 17:51:41 by azaliaus          #+#    #+#             */
/*   Updated: 2018/05/01 11:33:39 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

static void		call_recursive(t_file *files, t_opt *options)
{
	if (!(options->rec))
		return ;
	clean_options(options);
	while (files)
	{
		if (files->is_dir && (ft_strcmp(files->filename, ".") &&
						ft_strcmp(files->filename, "..")))
		{
			if (options->include_hidden)
				read_dir(files->filename, files->path, options, 0);
			else if (!is_file_hidden(files->filename))
				read_dir(files->filename, files->path, options, 0);
		}
		files = files->next;
	}
}

static void		display_error(t_opt *options, const char *filename,
	const char *path, int root)
{
	if (errno != ENOENT)
	{
		print_header(options, filename, path, root);
		print_error(filename);
	}
}

void			read_dir(const char *filename, const char *path, t_opt *options,
		int root)
{
	DIR				*dir;
	struct dirent	*dp;
	t_file			*files;
	t_file			*last;

	dir = opendir(path);
	if (is_file(path) && !(dir && !(options->long_list)))
		return ;
	files = NULL;
	last = files;
	if (!dir)
		display_error(options, filename, path, root);
	else
	{
		print_header(options, filename, path, root);
		options->count++;
		while ((dp = readdir(dir)) != NULL)
			file_push_back(&files, init_file(dp->d_name, path), &last, options);
		sort_files(options, &files);
		reverse_files_list(&files, options);
		format_output(files, options, TRUE);
		call_recursive(files, options);
		clean_files_memory(files, options);
		closedir(dir);
	}
}

void			process_dirs(int start_point, int ac, char **av, t_opt *options)
{
	char		*path;

	while (start_point < ac)
	{
		if (av[start_point][0] == '/' || av[start_point][0] == '.')
			read_dir(av[start_point], av[start_point], options, 1);
		else
		{
			if (av[start_point][ft_strlen(av[start_point]) - 1] != '/')
				path = ft_strjoin_conn(".", av[start_point], '/');
			else
				path = ft_strdup(av[start_point]);
			read_dir(av[start_point], path, options, 1);
			free(path);
		}
		start_point++;
	}
}
