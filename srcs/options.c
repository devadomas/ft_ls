/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 09:26:55 by azaliaus          #+#    #+#             */
/*   Updated: 2018/05/01 08:00:50 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

t_opt			*init_opt(void)
{
	t_opt		*ret;

	if (!(ret = (t_opt *)malloc(sizeof(t_opt))) ||
			!(ret->window = (struct winsize *)malloc(sizeof(struct winsize))) ||
			!(ret->charset = ft_strdup("1afglorRtuz")))
		return (0);
	ret->rec = 0;
	ret->long_list = 0;
	ret->include_hidden = 0;
	ret->reversed = 0;
	ret->sorted_t = 0;
	ret->one = 0;
	ret->count = 0;
	ret->hlink_offset = 0;
	ret->owner_offset = 0;
	ret->group_offset = 0;
	ret->size_offset = 0;
	ret->title_offset = 0;
	ret->total = 0;
	ret->total_files = 0;
	ret->flag_u = 0;
	ret->flag_f = 0;
	ret->flag_g = 0;
	ret->flag_o = 0;
	return (ret);
}

int				opt_count(t_opt *opt)
{
	int ret;

	ret = 0;
	ret += opt->rec + opt->long_list + opt->include_hidden + opt->reversed +
		opt->sorted_t + opt->one + opt->flag_u + opt->flag_f + opt->flag_g +
		opt->flag_o + opt->color;
	return (ret);
}

static int		check_charset(const char *str, t_opt *options)
{
	int		i;
	int		found;
	char	*charset;

	charset = options->charset;
	while (*str)
	{
		i = 0;
		found = 0;
		while (charset[i])
		{
			if (*str == charset[i])
				found = 1;
			i++;
		}
		if (!found && opt_count(options))
			return (0);
		if (!found)
			print_usage(*str, options);
		str++;
	}
	return (1);
}

static int		parse_options(t_opt *ret, char *str)
{
	ret->color = 0;
	while (*str)
	{
		if (!check_charset((str + 1), ret))
			return (0);
		ret->rec = (*str == 'R' ? 1 : ret->rec);
		ret->long_list = (*str == 'l' ? set_dup_arg(ret, 'l') : ret->long_list);
		ret->include_hidden = (*str == 'a' ? 1 : ret->include_hidden);
		ret->reversed = (*str == 'r' ? 1 : ret->reversed);
		ret->sorted_t = (*str == 't' ? 1 : ret->sorted_t);
		ret->one = (*str == '1' ? set_dup_arg(ret, '1') : ret->one);
		ret->flag_u = (*str == 'u' ? 1 : ret->flag_u);
		ret->flag_g = (*str == 'g' ? set_dup_arg(ret, 'g') : ret->flag_g);
		ret->flag_o = (*str == 'o' ? set_dup_arg(ret, 'o') : ret->flag_o);
		ret->flag_f = (*str == 'f' ? set_dup_arg(ret, 'f') : ret->flag_f);
		ret->color = (*str == 'z' ? 1 : ret->color);
		str++;
	}
	return (1);
}

int				load_options(t_opt *options, int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (ft_strlen(av[i]) == 2 && av[i][0] == '-' && av[i][1] == '-')
		{
			i++;
			if (i == ac)
				break ;
		}
		if (av[i][0] != '-' || (av[i][0] == '-' && ft_strlen(av[i]) < 2))
			break ;
		else
		{
			if (!parse_options(options, av[i]))
				break ;
		}
		i++;
	}
	check_args(i, ac, av);
	options->total_files = ac - i - 1;
	return (i);
}
