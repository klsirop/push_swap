/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 12:43:55 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/27 13:20:45 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

int		ft_is_sorted_b(t_lis **help)
{
	if (help && *help)
		return (1);
	return (0);
}

int		ft_is_sorted_a(t_lis **list)
{
	int		tmp;
	t_lis	*t;

	if (list && *list)
	{
		t = *list;
		if (t && t->next)
		{
			tmp = t->el;
			t = t->next;
		}
		else
			return (0);
		while (t)
		{
			if (tmp > t->el)
				return (1);
			tmp = t->el;
			t = t->next;
		}
	}
	return (0);
}

void	ft_is_sorted(t_lis **list, t_lis **help)
{
	if (ft_is_sorted_b(help) == 1)
	{
		ft_putstr("KO\n");
		return ;
	}
	if (ft_is_sorted_a(list) == 1)
	{
		ft_putstr("KO\n");
		return ;
	}
	ft_putstr("OK\n");
}
