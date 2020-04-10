/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sense.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:32:58 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/25 13:33:58 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

int		ft_test_swap(t_lis **list, t_lis **help)
{
	ft_list_swap(help);
	if (ft_begginer(list, help) || ft_first_second(list, help) ||
		ft_ending(list, help, ft_find_list_end(list)))
	{
		ft_list_swap(help);
		return (3);
	}
	else
	{
		ft_list_swap(help);
	}
	return (0);
}

int		ft_test_rotate(t_lis **list, t_lis **help)
{
	ft_list_rotate(help);
	if (ft_begginer(list, help) || ft_first_second(list, help) ||
		ft_ending(list, help, ft_find_list_end(list)))
	{
		ft_list_rev_rotate(help);
		return (2);
	}
	else
	{
		ft_list_rev_rotate(help);
	}
	return (0);
}

int		ft_test_rev_rotate(t_lis **list, t_lis **help)
{
	ft_list_rev_rotate(help);
	if (ft_begginer(list, help) || ft_first_second(list, help) ||
		ft_ending(list, help, ft_find_list_end(list)))
	{
		ft_list_rotate(help);
		return (1);
	}
	else
	{
		ft_list_rotate(help);
	}
	return (0);
}

int		ft_choose_rotate(t_lis **list, t_lis **help)
{
	if (ft_test_swap(list, help) == 3)
		return (3);
	if (ft_test_rotate(list, help) == 2)
		return (2);
	if (ft_test_rotate(list, help) == 1)
		return (1);
	return (0);
}

int		ft_break(t_lis **list)
{
	t_lis *tmp;

	tmp = *list;
	while (tmp)
	{
		if ((tmp->next) && ((tmp->el) > (tmp->next)->el))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
