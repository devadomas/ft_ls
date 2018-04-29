/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:19:44 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/29 17:37:31 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_header(t_opt *options, const char *filename, const char *path,
		int root)
{
	if (options->count)
		ft_putchar('\n');
	if (options->total_files > 0 || (options->rec && options->count))
	{
		ft_putstr((options->rec && !root ? path : filename));
		ft_putstr(":\n");
	}
}

void		sort_files(t_opt *options, t_file **files)
{
	if (options->sorted_t)
		sort_files_bytime(files);
	else
		sort_files_byname(files);
}

void		print_symlink(t_file *file)
{
	if (!file)
		return ;
	if (file->symlink)
	{
		ft_putstr(" -> ");
		ft_putstr(file->symlink);
	}
}

void		print_total(t_file *files, t_opt *options, t_bool long_mode)
{
	int count;

	if (!files || !options)
		return ;
	count = get_file_list_len(files, options->include_hidden);
	if (long_mode && count)
	{
		ft_putstr("total ");
		ft_putnbr(options->total);
		ft_putchar('\n');
	}
}

char		*init_path(const char *path, const char *filename)
{
	char		*ret;

	ret = NULL;
	if (ft_strlen(path) == 1 && *path == '/')
		ret = ft_strjoin(path, filename);
	else
		ret = ft_strjoin_conn(path, filename, '/');
	return (ret);
}
