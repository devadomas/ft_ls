/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 09:44:35 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/25 13:53:01 by azaliaus         ###   ########.fr       */
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
# include <sys/xattr.h>
/* Kernel interface */
# include <sys/ioctl.h>
# define TRUE		1
# define FALSE		0
# define ABS(Value) (Value < 0 ? -Value : Value)
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
	int					title_offset;
	int					total;
	char				*charset;
	struct winsize		*window;
}						t_opt;

typedef struct			s_file
{
	char				*filename;
	char				*path;
	int					is_dir;
	struct stat			*sb;
	char				*gname;
	char				*uname;
	char				*symlink;
	struct s_file		*next;
}						t_file;

void		ft_ls(int ac, char **av);
t_opt		*init_opt(void);
int			load_options(t_opt *options, int ac, char **av);
void		print_error(const char *filename);
void		file_push(t_file **list, t_file *file);
t_file		*init_file(const char *filename, const char *path, t_opt *options);
void		format_output(t_file *files, t_opt *options);
t_bool		is_file_hidden(const char *filename);
void		sort_files_byname(t_file **files, t_bool reversed);
void		load_offsets(t_file *list, t_opt *options);
void		clean_files_memory(t_file *files, t_opt *options);
void		clean_options_memory(t_opt *options);
int			get_file_list_len(t_file *files, int hidden);
t_file		*get_nth_file(t_file *files, unsigned int nth, int hidden);
void		print_usage(const char option, t_opt *options);

#endif
