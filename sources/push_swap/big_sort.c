/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:36:55 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/26 17:47:53 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

void	ft_izi_sort_a(t_lis **list)
{
	if ((ft_min_len(list) > (ft_find_list_len(list) / 2 + 1)))
	{
		while (ft_is_sorted_a(list) != 0)
		{
			ft_list_rev_rotate(list);
			ft_putstr("rra\n");
		}
	}
	else
	{
		while (ft_is_sorted_a(list) != 0)
		{
			ft_list_rotate(list);
			ft_putstr("ra\n");
		}
	}
}

int		ft_became_a_izi_sort(t_lis **list, t_lis **help)
{
	int median;
	int len;

	if (ft_find_median(list, &median) == -1)
		return (-1);
	len = ft_find_list_len(list);
	while (!(ft_izi_rotate(list)))
	{
		ft_list_push(help, list);
		ft_putstr("pb\n");
		if ((len > 5) && (*help) && ((*help)->next) && ((*help)->el < median))
		{
			ft_list_rotate(help);
			ft_putstr("rb\n");
		}
	}
	return (0);
}

void	ft_rotate_list(t_lis **list, t_lis *move)
{
	int len;
	int i;
	int ll;

	len = ft_new_tmp_len(list, move);
	ll = ft_find_list_len(list);
	if (ll - len < len)
		len = -(ll - len);
	i = 0;
	while ((len < 0) && (i < ft_abs(len)))
	{
		i++;
		ft_list_rev_rotate(list);
		ft_putstr("rra\n");
	}
	while ((len > 0) && (i < ft_abs(len)))
	{
		i++;
		ft_list_rotate(list);
		ft_putstr("ra\n");
	}
}

void	ft_rotate_help(t_lis **help, t_lis *move)
{
	int len;
	int i;
	int lh;

	i = 0;
	lh = ft_find_list_len(help);
	len = ft_tmp_hlen(help, move);
	if (lh - len < len)
		len = -(lh - len);
	while ((len < 0) && (i < ft_abs(len)))
	{
		i++;
		ft_list_rev_rotate(help);
		ft_putstr("rrb\n");
	}
	while ((len > 0) && (i < ft_abs(len)))
	{
		i++;
		ft_list_rotate(help);
		ft_putstr("rb\n");
	}
}

int		ft_big_sort(t_lis **list, t_lis **help)
{
	if (ft_became_a_izi_sort(list, help) == -1)
		return (-1);
	if (ft_new_put_elements_mid(list, help) == -1)
		return (-1);
	ft_izi_sort_a(list);
	return (0);
}
