/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 19:02:52 by azaliaus          #+#    #+#             */
/*   Updated: 2018/05/01 09:47:38 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_gaps(int offset)
{
	int i;

	i = 0;
	while (i < offset)
	{
		ft_putchar(' ');
		i++;
	}
}

void		print_str(const char *str, int offset, t_bool right, t_bool space)
{
	if (!str)
		return ;
	offset -= ft_strlen(str);
	if (right)
		print_gaps(offset);
	ft_putstr(str);
	if (!right)
		print_gaps(offset);
	if (space)
		ft_putchar(' ');
}

void		print_nbr(long long nbr, int offset, t_bool right, t_bool space)
{
	offset -= ft_get_nbr_len(nbr);
	if (right)
		print_gaps(offset);
	ft_putnbr(nbr);
	if (!right)
		print_gaps(offset);
	if (space)
		ft_putchar(' ');
}

void		print_color_offset(t_file *file, t_opt *options, int offset)
{
	if (!file)
		return ;
	offset -= ft_strlen(file->filename);
	color_output(file, options);
	print_gaps(offset);
}

void		color_output(t_file *file, t_opt *options)
{
	if (!(file->filename))
		return ;
	if (options->color)
	{
		if (S_ISDIR(file->sb->st_mode))
			ft_putstr(COLOR_CYAN);
		else if (file->symlink)
			ft_putstr(COLOR_MAGENTA);
		else if (file->sb->st_mode & S_IXUSR)
			ft_putstr(COLOR_RED);
	}
	ft_putstr(file->filename);
	if (options->color)
		ft_putstr(COLOR_RESET);
}
