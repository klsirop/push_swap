/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:00:01 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/31 18:00:22 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

void	ft_delete_list(t_lis **list)
{
	t_lis *tmp;

	while (list && *list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
	*list = NULL;
}

void	ft_printf_1_help(t_lis **list, t_lis **help, t_lis *tmp_l, t_lis *tmp_h)
{
	while ((list && tmp_l) || (help && tmp_h))
	{
		if (list && tmp_l && help && tmp_h)
		{
			ft_printf("     %d           %d    \n", tmp_l->el, tmp_h->el);
			tmp_l = tmp_l->next;
			tmp_h = tmp_h->next;
		}
		else if (list && tmp_l)
		{
			ft_printf("     %d               \n", tmp_l->el);
			tmp_l = tmp_l->next;
		}
		else if (help && tmp_h)
		{
			ft_printf("                 %d    \n", tmp_h->el);
			tmp_h = tmp_h->next;
		}
	}
}

void	ft_print_1(t_lis **list, t_lis **help)
{
	t_lis *tmp_l;
	t_lis *tmp_h;

	tmp_l = NULL;
	tmp_h = NULL;
	ft_printf("   LIST A:     LIST B:   \n");
	if (list || help)
	{
		if (list && *list)
			tmp_l = *list;
		if (help && *help)
			tmp_h = *help;
		ft_printf_1_help(list, help, tmp_l, tmp_h);
	}
}

void	ft_print_list(t_lis **list, t_lis **help, int *flag)
{
	if (*flag == 1)
		ft_print_1(list, help);
	if (*flag == 3)
		ft_print_colour(list, help);
}
