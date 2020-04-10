/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_doings_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 12:37:24 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/25 13:02:03 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

void	ft_list_rev_rotate(t_lis **list)
{
	void	*tmp;
	t_lis	*i;

	if (!(list && *list && (*list)->next))
		return ;
	i = *list;
	while (i && i->next && (i->next)->next)
		i = i->next;
	tmp = i;
	(i->next)->next = *list;
	*list = i->next;
	i = tmp;
	i->next = NULL;
}

void	ft_list_rev_rotate_all(t_lis **list, t_lis **help)
{
	ft_list_rev_rotate(list);
	ft_list_rev_rotate(help);
}
