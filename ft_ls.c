/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 09:45:11 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/22 20:57:12 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#include <stdio.h>

/*static void		print_type(char *filename)
{
	struct stat			sb;

	if (stat(filename, &sb) < 0)
		return ;
	printf((S_ISBLK(sb.st_mode)) ? "block device" : "");
	printf((S_ISCHR(sb.st_mode)) ? "character device" : "");
	printf((S_ISDIR(sb.st_mode)) ? "directory" : "");
	printf((S_ISFIFO(sb.st_mode)) ? "FIFO/pipe" : "");
	printf((S_ISLNK(sb.st_mode)) ? "symlink" : "");
	printf((S_ISREG(sb.st_mode)) ? "regular file" : "");
	printf((S_ISSOCK(sb.st_mode)) ? "socket" : "");
}

static void		print_permissions(char *filename)
{
	struct stat			sb;

	if (stat(filename, &sb) < 0)
	{
		printf("----------");
		return ;
	}
	printf((S_ISDIR(sb.st_mode)) ? "d" : "-");
	printf((sb.st_mode & S_IRUSR) ? "r" : "-");
	printf((sb.st_mode & S_IWUSR) ? "w" : "-");
	printf((sb.st_mode & S_IXUSR) ? "x" : "-");
	printf((sb.st_mode & S_IRGRP) ? "r" : "-");
	printf((sb.st_mode & S_IWGRP) ? "w" : "-");
	printf((sb.st_mode & S_IXGRP) ? "x" : "-");
	printf((sb.st_mode & S_IROTH) ? "r" : "-");
	printf((sb.st_mode & S_IWOTH) ? "w" : "-");
	printf((sb.st_mode & S_IXOTH) ? "x" : "-");
}*/

static void		read_dir(char *filename, t_opt *options)
{
	DIR				*dir;
	struct dirent	*dp;
	//struct stat		sb;
	t_file			*files;
	t_file			*cpy;

	dir = opendir(filename);
	files = NULL;
	if (!dir)
		print_error(filename);
	else
	{
		if (options->count != 0)
			printf("%s:\n", filename);
		options->count++;
		while ((dp = readdir(dir)) != NULL)
			file_push(&files, init_file(dp->d_name));
		cpy = files;
		while (files)
		{
			printf("filename: %s <-> dir: %d\n", files->filename, files->is_dir);
			files = files->next;
		}
		if (options->rec)
		{
			while (cpy)
			{
				if (cpy->is_dir && (!ft_strcmp(cpy->filename, ".") || !ft_strcmp(cpy->filename, "..")))
				{
					read_dir(cpy->filename, options);
				}
				cpy = cpy->next;
			}
		}
		(void)closedir(dir);
	}
}

void			ft_ls(int ac, char **av)
{
	t_opt	*options;
	int		start_point;

	options = init_opt();
	start_point = load_options(options, ac, av);

	printf("Starting point: %d\n", start_point);
	printf("---\nLoaded options:\n");
	printf("Recursive: %d\n", options->rec);
	printf("Long list: %d\n", options->long_list);
	printf("Include hidden: %d\n", options->include_hidden);
	printf("Reversed: %d\n", options->reversed);
	printf("Sorted t: %d\n", options->sorted_t);
	printf("---\n");
	if (start_point == ac)
		read_dir(".", options);
	else
		while (start_point < ac)
			read_dir(av[start_point++], options);
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
