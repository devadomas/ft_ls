/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 09:44:35 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/30 18:13:35 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include <sys/ioctl.h>
# include <errno.h>

# define TRUE			1
# define FALSE			0
# define ABS(Value)		(Value < 0 ? -Value : Value)

# define LINK_BUFF		512

# define COLOR_RED		"\x1b[31m"
# define COLOR_GREEN	"\x1b[32m"
# define COLOR_YELLOW	"\x1b[33m"
# define COLOR_BLUE		"\x1b[34m"
# define COLOR_MAGENTA	"\x1b[35m"
# define COLOR_CYAN		"\x1b[36m"
# define COLOR_RESET	"\x1b[0m"

typedef int				t_bool;

typedef struct			s_opt
{
	int					rec;
	int					long_list;
	int					include_hidden;
	int					reversed;
	int					sorted_t;
	int					one;
	int					count;
	int					hlink_offset;
	int					owner_offset;
	int					group_offset;
	int					size_offset;
	int					title_offset;
	int					total;
	int					total_files;
	int					flag_u;
	int					flag_f;
	int					flag_g;
	int					flag_o;
	int					color;
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

void					ft_ls(int ac, char **av);
t_opt					*init_opt(void);
int						load_options(t_opt *options, int ac, char **av);
void					print_error(const char *filename);
t_file					*init_file(const char *filename, const char *path);
void					read_dir(const char *filename, const char *path,
	t_opt *options, int root);
void					format_output(t_file *files, t_opt *options,
	t_bool long_mode);
void					format_long(t_file *files, t_opt *options,
	t_bool long_mode);
t_bool					is_file_hidden(const char *filename);
void					sort_files_byname(t_file **files);
void					sort_files_bytime(t_file **files);
void					sort_files_bytime_u(t_file **files);
void					load_offset(t_file *file, t_opt *options);
void					clean_files_memory(t_file *files, t_opt *options);
void					clean_options_memory(t_opt *options);
int						get_file_list_len(t_file *files, int hidden);
t_file					*get_nth_file(t_file *files, unsigned int nth,
	int hidden);
void					print_usage(const char option, t_opt *options);
void					reverse_files_list(t_file **files, t_opt *options);
t_bool					is_file(const char *path);
void					process_files(int begin, int ac, char **av,
	t_opt *options);
void					clean_options(t_opt *options);
void					sort_arguments(int begin, int ac, char **av);
void					print_header(t_opt *options, const char *filename,
	const char *path, int root);
void					sort_files(t_opt *options, t_file **files);
void					print_str(const char *str, int offset, t_bool right,
	t_bool space);
void					print_nbr(long long nbr, int offset, t_bool right,
	t_bool space);
void					file_push_back(t_file **list, t_file *file,
	t_file **lst, t_opt *options);
void					print_symlink(t_file *file);
void					print_total(t_file *files, t_opt *options,
	t_bool long_mode);
char					*init_path(const char *path, const char *filename);
void					print_arg_empty(void);
void					check_args(int begin, int ac, char **av);
void					precheck_args(int begin, int ac, char **av);
void					print_acl(t_file *file);
int						set_dup_arg(t_opt *options, char arg);
void					color_output(t_file *file, t_opt *options);
void					process_dirs(int start_point, int ac, char **av,
	t_opt *options);

#endif
