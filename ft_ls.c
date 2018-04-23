/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 09:45:11 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/23 19:06:25 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#include <stdio.h>

static void		read_dir(const char *filename, const char *path, t_opt *options);

static void		call_recursive(t_file *files, t_opt *options)
{
	while (files)
	{
		if (files->is_dir && (ft_strcmp(files->filename, ".") &&
						ft_strcmp(files->filename, "..")))
			read_dir(files->filename, files->path, options);
		files = files->next;
	}
}

static void		read_dir(const char *filename, const char *path, t_opt *options)
{
	DIR				*dir;
	struct dirent	*dp;
	t_file			*files;
	t_file			*cpy;

	dir = opendir(path);
	files = NULL;
	if (!dir)
		print_error(filename);
	else
	{
		if (options->count != 0)
			printf("\n%s:\n", path);
		options->count++;
		while ((dp = readdir(dir)) != NULL)
			file_push(&files, init_file(dp->d_name, path));
		sort_files_byname(&files, (options->reversed ? TRUE : FALSE));
		load_offsets(files, options);
		//printf("Size offset: %d\n", options->size_offset);
		cpy = files;
		while (files)
		{
			/*printf("filename: %s\n", files->filename);
			printf("\tdir: %d <-> path: %s\n", files->is_dir, files->path);*/
			format_output(files, options);
			files = files->next;
		}
		if (options->rec)
			call_recursive(cpy, options);
		closedir(dir);
	}
}

void			ft_ls(int ac, char **av)
{
	t_opt	*options;
	int		start_point;

	options = init_opt();
	start_point = load_options(options, ac, av);

	/*printf("Starting point: %d\n", start_point);
	printf("---\nLoaded options:\n");
	printf("Recursive: %d\n", options->rec);
	printf("Long list: %d\n", options->long_list);
	printf("Include hidden: %d\n", options->include_hidden);
	printf("Reversed: %d\n", options->reversed);
	printf("Sorted t: %d\n", options->sorted_t);
	printf("---\n");*/
	if (start_point == ac)
		read_dir(".", ".", options);
	else
	{
		while (start_point < ac)
		{
			char *path;
			path = ft_strjoin_conn(".", av[start_point], '/');
			read_dir(av[start_point++], path, options);
		}
	}
}

/*(void)ac;
	(void)av;
	DIR				*dir;
	struct dirent	*dp;
	//struct stat		sb;

	dir = opendir(".");
	if (!dir)
		return ;
	while ((dp = readdir(dir)))
	{
		print("File: %s | ", dp->d_name);
		print_permissions(dp->d_name);
	}
	(void)closedir(dir);
*/
