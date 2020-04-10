/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_doings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:27:28 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/25 13:04:22 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

void	ft_list_swap(t_lis **list)
{
	t_lis *tmp;

	if (!(list && *list && (*list)->next))
		return ;
	tmp = (*list)->next;
	(*list)->next = ((*list)->next)->next;
	tmp->next = (*list);
	*list = tmp;
}

void	ft_list_swap_all(t_lis **list, t_lis **help)
{
	ft_list_swap(list);
	ft_list_swap(help);
}

void	ft_list_push(t_lis **list, t_lis **help)
{
	void *tmp;

	if (!((help && *help)))
		return ;
	tmp = (*help)->next;
	(*help)->next = *list;
	*list = *help;
	*help = tmp;
}

void	ft_list_rotate(t_lis **list)
{
	void	*tmp;
	t_lis	*i;

	if (!((list && *list && (*list)->next)))
		return ;
	tmp = (*list)->next;
	i = *list;
	while (i->next)
		i = i->next;
	i->next = *list;
	(*list)->next = NULL;
	*list = tmp;
}

void	ft_list_rotate_all(t_lis **list, t_lis **help)
{
	ft_list_rotate(list);
	ft_list_rotate(help);
}
