/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 09:26:55 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/26 16:24:14 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

t_opt			*init_opt(void)
{
	t_opt		*ret;

	if (!(ret = (t_opt *)malloc(sizeof(t_opt))))
		return (0);
	if (!(ret->window = (struct winsize *)malloc(sizeof(struct winsize))))
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
	if (!(ret->charset = ft_strdup("1alrRt")))
	{
		free(ret->window);
		free(ret);
		return (0);
	}
	return (ret);
}

/*
 * TODO: add other options when bonus added
 */
int			opt_count(t_opt *opt)
{
	int ret;

	ret = 0;
	ret += opt->rec + opt->long_list + opt->include_hidden + opt->reversed +
		opt->sorted_t + opt->one;
	return (ret);
}

static void	check_charset(const char *str, t_opt *options)
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
			return ;
		if (!found)
			print_usage(*str, options);
		str++;
	}
}

static void	parse_options(t_opt *ret, char *str)
{
	while (*str)
	{
		check_charset((str + 1), ret);
		ret->rec = (*str == 'R' ? 1 : ret->rec);
		ret->long_list = (*str == 'l' ? 1 : ret->long_list);
		ret->include_hidden = (*str == 'a' ? 1 : ret->include_hidden);
		ret->reversed = (*str == 'r' ? 1 : ret->reversed);
		ret->sorted_t = (*str == 't' ? 1 : ret->sorted_t);
		ret->one = (*str == '1' ? 1 : ret->one);
		str++;
	}
}

int			load_options(t_opt *options, int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] != '-' || (av[i][0] == '-' && ft_strlen(av[i]) < 2))
			break ;
		else
			parse_options(options, av[i]); 
		i++;
	}
	return (i);
}
