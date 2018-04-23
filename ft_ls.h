/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 09:44:35 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/23 19:42:50 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

# include "libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <uuid/uuid.h>
# define TRUE		1
# define FALSE		0

typedef int t_bool;

typedef struct			s_opt
{
	int					rec;
	int					long_list;
	int					include_hidden;
	int					reversed;
	int					sorted_t;
	int					count;
	int					hlink_offset;
	int					owner_offset;
	int					group_offset;
	int					size_offset;
	int					total;
}						t_opt;

typedef struct			s_file
{
	char				*filename;
	char				*path;
	int					is_dir;
	struct stat			*sb;
	char				*gname;
	char				*uname;
	struct s_file		*next;
}						t_file;

void		ft_ls(int ac, char **av);
t_opt		*init_opt(void);
int			load_options(t_opt *options, int ac, char **av);
void		print_error(const char *filename);
void		file_push(t_file **list, t_file *file);
t_file		*init_file(const char *filename, const char *path);
void		format_output(t_file *file, t_opt *options);
t_bool		is_file_hidden(const char *filename);
void		sort_files_byname(t_file **files, t_bool reversed);
void		load_offsets(t_file *list, t_opt *options);

#endif
