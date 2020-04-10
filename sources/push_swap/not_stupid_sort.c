/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_stupid_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:11:44 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/25 16:10:27 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

int		ft_first_second(t_lis **list, t_lis **help)
{
	t_lis *a;
	t_lis *b;

	if (!(list && help))
		return (0);
	a = *list;
	b = *help;
	if (a && a->next && b)
	{
		if ((b->el > a->el) && (b->el < (a->next)->el))
		{
			return (1);
		}
	}
	return (0);
}

int		ft_begginer(t_lis **list, t_lis **help)
{
	t_lis *a;
	t_lis *b;

	if (!(list && help))
		return (0);
	a = *list;
	b = *help;
	if (a && b)
	{
		if (b->el < a->el)
		{
			return (1);
		}
	}
	return (0);
}

int		ft_ending(t_lis **list, t_lis **help, t_lis *end)
{
	t_lis *b;

	if (!(list && help))
		return (0);
	b = *help;
	if (end && b)
	{
		if (b->el > end->el)
		{
			return (1);
		}
	}
	return (0);
}
