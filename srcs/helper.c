/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:19:44 by azaliaus          #+#    #+#             */
/*   Updated: 2018/05/01 16:34:34 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

void		sort_files(t_opt *options, t_file **files)
{
	if (options->flag_f)
		return ;
	if (options->sorted_t)
	{
		if (options->flag_u)
			sort_files_bytime_u(files);
		else
			sort_files_bytime(files);
	}
	else
		sort_files_byname(files);
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

char		**make_av_cpy(int ac, char **av)
{
	char		**ret;
	int			i;

	if (!(ret = (char **)malloc(sizeof(char *) * ac + 1)))
		return (NULL);
	ret[ac] = NULL;
	i = -1;
	while (++i < ac)
		ret[i] = av[i];
	return (ret);
}
