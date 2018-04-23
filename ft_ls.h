/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 09:44:35 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/22 20:54:40 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

#include "libft.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct			s_opt
{
	int					rec;
	int					long_list;
	int					include_hidden;
	int					reversed;
	int					sorted_t;
	int					count;
}						t_opt;

typedef struct			s_file
{
	char				*filename;
	char				*path;
	int					is_dir;
	struct s_file		*next;
}						t_file;

void		ft_ls(int ac, char **av);
t_opt		*init_opt(void);
int			load_options(t_opt *options, int ac, char **av);
void		print_error(char *filename);
void		file_push(t_file **list, t_file *file);
t_file		*init_file(char *filename);

#endif
