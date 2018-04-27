/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 09:45:11 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/27 14:00:25 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>


static void		read_dir(const char *filename, const char *path, t_opt *options,
		int root);

static void		call_recursive(t_file *files, t_opt *options)
{
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

static void		read_dir(const char *filename, const char *path, t_opt *options,
		int root)
{
	DIR				*dir;
	struct dirent	*dp;
	t_file			*files;
	
	if (is_file(path))
		return ;
	dir = opendir(path);
	files = NULL;
	printf((options->count ? "\n" : ""));
	if (options->total_files > 0 || (options->rec && options->count))
		printf("%s:\n", (options->rec && !root ? path : filename));
	if (!dir)
		print_error(filename);
	else
	{
		options->count++;
		while ((dp = readdir(dir)) != NULL)
			file_push(&files, init_file(dp->d_name, path, options));

		if (options->sorted_t)
			sort_files_bytime(&files);
		else
			sort_files_byname(&files, (options->reversed ? TRUE : FALSE));
		
		if (options->reversed)
			reverse_files_list(&files);
		load_offsets(files, options);
		format_output(files, options, TRUE);
		if (options->rec)
			call_recursive(files, options);
		clean_files_memory(files, options);
		closedir(dir);
	}
}

void			ft_ls(int ac, char **av)
{
	t_opt	*options;
	int		start_point;
	char	*path;

	options = init_opt();
	start_point = load_options(options, ac, av);
	options->total_files = ac - start_point - 1;
	/*printf("Starting point: %d\n", start_point);
	printf("---\nLoaded options:\n");
	printf("Recursive: %d\n", options->rec);
	printf("Long list: %d\n", options->long_list);
	printf("Include hidden: %d\n", options->include_hidden);
	printf("Reversed: %d\n", options->reversed);
	printf("Sorted t: %d\n", options->sorted_t);
	printf("---\n");*/
	if (start_point == ac)
		read_dir(".", ".", options, 1);
	else
	{
		process_files(start_point, ac, av, options);
		while (start_point < ac)
		{
			if (av[start_point][0] == '/' || av[start_point][0] == '.')
				read_dir(av[start_point], av[start_point], options, 1);
			else
			{
				int len = ft_strlen(av[start_point]);
				if (av[start_point][len - 1] != '/')
					path = ft_strjoin_conn(".", av[start_point], '/');
				else
					path = av[start_point];
				read_dir(av[start_point], path, options, 1);
				//free(path);
			}
			start_point++;
		}
	}
	clean_options_memory(options);
}
