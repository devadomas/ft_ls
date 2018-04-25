/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 09:26:55 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/25 15:06:21 by azaliaus         ###   ########.fr       */
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
	ret->count = 0;
	ret->hlink_offset = 0;
	ret->owner_offset = 0;
	ret->group_offset = 0;
	ret->size_offset = 0;
	ret->title_offset = 0;
	ret->total = 0;
	if (!(ret->charset = ft_strdup("alR")))
	{
		free(ret->window);
		free(ret);
		return (0);
	}
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
