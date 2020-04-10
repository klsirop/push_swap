/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:24:13 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/31 16:17:03 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

void	ft_print_col_h(t_lis **list, t_lis **help, t_lis *tmp_l, t_lis *tmp_h)
{
	while ((list && tmp_l) || (help && tmp_h))
	{
		if (list && tmp_l && help && tmp_h)
		{
			ft_printf(RED "     %d" RED GREEN "           %d    "
						GREEN RESET "\n" RESET, tmp_l->el, tmp_h->el);
			tmp_l = tmp_l->next;
			tmp_h = tmp_h->next;
		}
		else if (list && tmp_l)
		{
			ft_printf(RED "     %d               " RED RESET "\n"
						RESET, tmp_l->el);
			tmp_l = tmp_l->next;
		}
		else if (help && tmp_h)
		{
			ft_printf(GREEN "                 %d    " GREEN RESET "\n"
						RESET, tmp_h->el);
			tmp_h = tmp_h->next;
		}
	}
}

void	ft_print_colour(t_lis **list, t_lis **help)
{
	t_lis *tmp_l;
	t_lis *tmp_h;

	tmp_l = NULL;
	tmp_h = NULL;
	ft_printf(CYAN "   LIST A:      LIST B:   " CYAN "\n");
	if (list || help)
	{
		if (list && *list)
			tmp_l = *list;
		if (help && *help)
			tmp_h = *help;
		ft_print_col_h(list, help, tmp_l, tmp_h);
	}
}

int		ft_error(t_lis **list, t_lis **help)
{
	ft_putstr_fd("Error\n", 2);
	if (list && *list)
		ft_delete_list(list);
	if (help && *help)
		ft_delete_list(help);
	return (-1);
}
