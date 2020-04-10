/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:20:02 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/31 17:41:14 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# ifndef UNISTD_H
#  define UNISTD_H
#  include <unistd.h>
# endif
# ifndef STDLIB_H
#  define STDLIB_H
#  include <stdlib.h>
# endif
# ifndef __LIBFT_LIBFT_H
#  define __LIBFT_LIBFT_H
#  include "../libft/libft.h"
# endif

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

typedef	struct	s_lis
{
	int				el;
	struct s_lis	*next;
}				t_lis;

/*
** valid_command.c
*/

void			ft_check_line_help(char *line, t_lis **list,
								t_lis **help, int *flag);
int				ft_check_line(char *line, t_lis **list,
								t_lis **help, int *flag);
int				ft_valid_command(t_lis **list, t_lis **help, int *flag);

/*
** divide.c
*/

int				ft_find_slovo(char **arr, char const *s, int word, char c);
void			ft_clean(char **arr);
char			**ft_divide(char const *s, char c);

/*
** extra_func.c
*/

int				ft_error(t_lis **list, t_lis **help);
void			ft_delete_list(t_lis **list);
void			ft_printf_list_all(t_lis **list, t_lis **help);
void			ft_print_list(t_lis **list, t_lis **help, int *flag);

/*
** flags.c
*/

int				ft_find_flag(int i, char **argv, int *flag);
int				ft_valid_arg_ch(int argc, char **argv, t_lis **list, int *flag);

/*
** ft_new_atoi.c
*/

int				ft_print(int flag_min);
long int		ft_new_atoi(const char *str);

/*
** is_sorted.c
*/

int				ft_is_sorted_b(t_lis **help);
int				ft_is_sorted_a(t_lis **list);
void			ft_is_sorted(t_lis **list, t_lis **help);

/*
** list_doings_2.c
*/

void			ft_list_rev_rotate(t_lis **list);
void			ft_list_rev_rotate_all(t_lis **list, t_lis **help);

/*
** list_doings.c
*/
void			ft_list_swap(t_lis **list);
void			ft_list_swap_all(t_lis **list, t_lis **help);
void			ft_list_push(t_lis **list, t_lis **help);
void			ft_list_rotate(t_lis **list);
void			ft_list_rotate_all(t_lis **list, t_lis **help);

/*
** printf_list.c
*/

void			ft_print_colour(t_lis **list, t_lis **help);

/*
** valid_arg_help.c
*/

int				ft_add_to_list(char *str, t_lis **list, t_lis **head);
int				ft_check_arg(char *str);
int				ft_check_repeat(char **argv, int i);
int				ft_check_repeat_new(t_lis *head, char *str);
int				ft_space(char *str);

/*
** valid_arg.c
*/

int				ft_find_mas(char ***mas, char **argv, int i);
void			ft_free_mas(char **arr);
int				ft_help_valid_arg(int *tmp, char ***mas,
								t_lis **list, t_lis **head);
int				ft_valid_arg_ps(int argc, char **argv, t_lis **list);

/*
** all_len.c
*/

int				ft_tmp_hlen(t_lis **list, t_lis *find);
int				ft_find_this_len(t_lis **list, t_lis **help, t_lis *find);
int				ft_find_all_len(t_lis **list, t_lis **help, int **mas);
int				ft_find_min_mas(int *mas, int len);

/*
** big_sort.c
*/

void			ft_izi_sort_a(t_lis **list);
int				ft_became_a_izi_sort(t_lis **list, t_lis **help);
void			ft_rotate_list(t_lis **list, t_lis *move);
void			ft_rotate_help(t_lis **help, t_lis *move);
int				ft_big_sort(t_lis **list, t_lis **help);

/*
** find_alg.c
*/

int				ft_find_list_len(t_lis **list);
t_lis			*ft_find_list_end(t_lis **list);
int				ft_is_sort(t_lis **list, t_lis **help);

/*
** find_median.c
*/

int				ft_create_arr(t_lis **list, int **arr);
int				ft_find_median(t_lis **list, int *median);

/*
** find_sense.c
*/

int				ft_test_swap(t_lis **list, t_lis **help);
int				ft_test_rotate(t_lis **list, t_lis **help);
int				ft_test_rev_rotate(t_lis **list, t_lis **help);
int				ft_choose_rotate(t_lis **list, t_lis **help);
int				ft_break(t_lis **list);

/*
** middle_sort.c
*/

int				ft_find_min_mas_mid(int *mas, int len, t_lis **help);
void			ft_rotate_together(t_lis **list,
								t_lis **help, int lenh, int lenl);
void			ft_rev_rotate_together(t_lis **list, t_lis **help,
									int lenh, int lenl);
void			ft_put_rotate_all(t_lis **list, t_lis **help, t_lis *move);
int				ft_new_put_elements_mid(t_lis **list, t_lis **help);

/*
** not_stupid_sort.c
*/

int				ft_first_second(t_lis **list, t_lis **help);
int				ft_begginer(t_lis **list, t_lis **help);
int				ft_ending(t_lis **list, t_lis **help, t_lis *end);

/*
** put_elements.c
*/

int				ft_abs(int a);
void			ft_new_tmp_len_1(t_lis **tmp, t_lis *find, int *len, int *flag);
int				ft_new_tmp_len_2(t_lis **tmp, int *len, t_lis **list,
									t_lis *find);
void			ft_new_tmp_len_3(t_lis **tmp, int *len, t_lis *find);
int				ft_new_tmp_len(t_lis **list, t_lis *find);

/*
** stupid_sort.c
*/

t_lis			*ft_find_min_ps(t_lis **list);
int				ft_help_check_swap(t_lis **list, t_lis *tmp,
								t_lis *ptmp, t_lis *min);
int				ft_check_swap(t_lis **list);
int				ft_izi_rotate(t_lis **list);
int				ft_min_len(t_lis **list);

/*
** find_command.c
*/

int				get_next_line_wb(const int fd, char **line);
void			ft_init_val(int *i, char ***mas, t_lis **head);

#endif
