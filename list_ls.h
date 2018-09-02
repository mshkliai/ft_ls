/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ls.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:26:17 by mshkliai          #+#    #+#             */
/*   Updated: 2018/08/01 12:29:32 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_LS_H
# define LIST_LS_H

# include "./printf/libftprintf.h"

# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>

typedef struct dirent	t_dir;
typedef struct stat		t_stat;
typedef struct passwd	t_pass;
typedef struct group	t_group;

typedef struct			s_file
{
	char				*name;
	char				*pass;
	char				*group;
	int					is_dir;
	t_stat				info;
	struct s_file		*prev;
	struct s_file		*next;
}						t_file;

char					g_flags[9];
int						g_deep;
int						g_format;

int						max_space(t_file *file, int flag);
int						max_space_size(t_file *file, t_file *files);
void					read_link(char *name, char *buff);
void					ft_swap(t_file **file1, t_file **file2, int *j);
int						size_list(t_file *files);
void					out_error(int num, char *name);
void					get_end(t_file **file);
int						sorting_mass(char **mass);
void					parse_flags(char **av, int *i, char *flags);
void					parse_file(t_stat info, char *name, t_file **files);
void					print_file(t_file *file, int allow);
char					*join_separate(char *line, char *line2, char separate);
int						len_name(char *name);
void					list_del(t_file *list);
void					bubble(t_file **files);
void					add_file(t_file **files, char *name);
t_file					**sort_in_columns(t_file **files, int columns);
int						count_spaces(int num);
void					formating(t_file *files);
void					flag_l(t_file *files, int total);
void					ls_end(char **paths);

#endif
