/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:38:25 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/26 17:48:24 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

int		ft_find_min_mas_mid(int *mas, int len, t_lis **help)
{
	int		i;
	int		min;
	int		ind;
	t_lis	*tmp;
	t_lis	*lmin;

	i = 0;
	min = mas[i];
	ind = 0;
	tmp = *help;
	lmin = tmp;
	while (i < len)
	{
		if ((min > mas[i]) || ((min == mas[i]) && (lmin->el < tmp->el)))
		{
			min = mas[i];
			ind = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (ind);
}

void	ft_rotate_together(t_lis **list, t_lis **help, int lenh, int lenl)
{
	int ih;
	int il;

	ih = 0;
	il = 0;
	while ((ih < ft_abs(lenh)) && (il < ft_abs(lenl)))
	{
		ih++;
		il++;
		ft_list_rotate(help);
		ft_list_rotate(list);
		ft_putstr("rr\n");
	}
	while ((il < ft_abs(lenl)))
	{
		il++;
		ft_list_rotate(list);
		ft_putstr("ra\n");
	}
	while ((ih < ft_abs(lenh)))
	{
		ih++;
		ft_list_rotate(help);
		ft_putstr("rb\n");
	}
}

void	ft_rev_rotate_together(t_lis **list, t_lis **help, int lenh, int lenl)
{
	int ih;
	int il;

	ih = 0;
	il = 0;
	while ((ih < ft_abs(lenh)) && (il < ft_abs(lenl)))
	{
		ih++;
		il++;
		ft_list_rev_rotate(help);
		ft_list_rev_rotate(list);
		ft_putstr("rrr\n");
	}
	while ((il < ft_abs(lenl)))
	{
		il++;
		ft_list_rev_rotate(list);
		ft_putstr("rra\n");
	}
	while ((ih < ft_abs(lenh)))
	{
		ih++;
		ft_list_rev_rotate(help);
		ft_putstr("rrb\n");
	}
}

void	ft_put_rotate_all(t_lis **list, t_lis **help, t_lis *move)
{
	int lenh;
	int lenl;
	int il;
	int ih;

	ih = ft_find_list_len(help);
	il = ft_find_list_len(list);
	lenh = ft_tmp_hlen(help, move);
	if (ih - lenh < lenh)
		lenh = -(ih - lenh);
	lenl = ft_new_tmp_len(list, move);
	if (il - lenl < lenl)
		lenl = -(il - lenl);
	ih = 0;
	il = 0;
	if (((lenh <= 0) && (lenl >= 0)) || ((lenh >= 0) && (lenl <= 0)))
	{
		ft_rotate_list(list, move);
		ft_rotate_help(help, move);
	}
	else if ((lenh > 0) && (lenl > 0))
		ft_rotate_together(list, help, lenh, lenl);
	else if ((lenh < 0) && (lenl < 0))
		ft_rev_rotate_together(list, help, lenh, lenl);
}

int		ft_new_put_elements_mid(t_lis **list, t_lis **help)
{
	int		*mas;
	t_lis	*move;
	int		i;
	int		ind;

	mas = NULL;
	while (*help)
	{
		if (ft_find_all_len(list, help, &mas) == -1)
			return (-1);
		ind = ft_find_min_mas_mid(mas, ft_find_list_len(help), help);
		move = *help;
		i = 0;
		while (i < ind)
		{
			move = move->next;
			i++;
		}
		ft_put_rotate_all(list, help, move);
		ft_list_push(list, help);
		ft_putstr("pa\n");
		free(mas);
		mas = NULL;
	}
	return (0);
}
