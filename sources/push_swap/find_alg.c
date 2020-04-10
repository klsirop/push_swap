/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:16:14 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/27 13:20:28 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

int		ft_find_list_len(t_lis **list)
{
	t_lis	*tmp;
	int		len;

	len = 0;
	tmp = *list;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

t_lis	*ft_find_list_end(t_lis **list)
{
	t_lis *tmp;

	if (!(list))
		return (NULL);
	tmp = *list;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

int		ft_is_sort(t_lis **list, t_lis **help)
{
	if (ft_is_sorted_b(help) == 1)
	{
		return (0);
	}
	if (ft_is_sorted_a(list) == 1)
	{
		return (0);
	}
	return (1);
}
