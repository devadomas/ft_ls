/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 17:25:13 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/30 17:25:14 by azaliaus         ###   ########.fr       */
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
