/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:11:39 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/29 17:25:21 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include <unistd.h>

static void		format_cols(t_file *files, t_opt *options, int cols)
{
	int			i;
	int			j;
	int			len;
	int			index;
	t_file		*file;

	i = 0;
	len = get_file_list_len(files, options->include_hidden);
	if (len != 1)
		len = ft_floor_up((float)len / cols);
	while (i++ < len)
	{
		j = 0;
		while (j++ < cols)
		{
			index = (i - 1) + (j - 1) * (len);
			file = get_nth_file(files, index, options->include_hidden);
			if (!file)
				break ;
			print_str(file->filename, options->title_offset + 1, 0, 0);
		}
		ft_putchar('\n');
	}
}

void			format_simple(t_file *files, t_opt *options)
{
	while (files)
	{
		if (!(is_file_hidden(files->filename) && !(options->include_hidden)))
		{
			ft_putstr(files->filename);
			ft_putchar('\n');
		}
		files = files->next;
	}
}

void			format_output(t_file *files, t_opt *options, t_bool long_mode)
{
	int			cols;

	if (options->long_list)
		format_long(files, options, long_mode);
	else if (options->one)
		format_simple(files, options);
	else
	{
		ioctl(STDOUT_FILENO, TIOCGWINSZ, options->window);
		cols = (options->window)->ws_col / (options->title_offset + 1);
		if (!cols)
			format_simple(files, options);
		else
			format_cols(files, options, cols);
	}
}
