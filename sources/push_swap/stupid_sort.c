/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stupid_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 17:44:01 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/27 15:22:05 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

t_lis	*ft_find_min_ps(t_lis **list)
{
	t_lis	*tmp;
	int		min;
	t_lis	*ret;

	tmp = *list;
	if (tmp)
	{
		min = tmp->el;
		ret = tmp;
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (tmp->el < min)
		{
			min = tmp->el;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

int		ft_help_check_swap(t_lis **list, t_lis *tmp, t_lis *ptmp, t_lis *min)
{
	while (tmp != min)
	{
		if (tmp->el < ptmp->el)
			return (1);
		ptmp = ptmp->next;
		tmp = tmp->next;
		if (tmp == NULL)
			tmp = *list;
		if (ptmp == NULL)
			ptmp = *list;
	}
	return (0);
}

int		ft_check_swap(t_lis **list)
{
	t_lis	*min;
	t_lis	*tmp;
	t_lis	*ptmp;
	int		flag;

	ft_list_swap(list);
	min = ft_find_min_ps(list);
	ptmp = min;
	tmp = min->next;
	if (tmp == NULL)
		tmp = *list;
	if (ptmp == NULL)
		ptmp = *list;
	flag = ft_help_check_swap(list, tmp, ptmp, min);
	if (flag == 1)
	{
		ft_list_swap(list);
		return (1);
	}
	else
		ft_putstr("sa\n");
	return (0);
}

int		ft_izi_rotate(t_lis **list)
{
	t_lis	*min;
	t_lis	*tmp;
	t_lis	*ptmp;
	int		flag;

	min = ft_find_min_ps(list);
	ptmp = min;
	tmp = min->next;
	if (tmp == NULL)
		tmp = *list;
	if (ptmp == NULL)
		ptmp = *list;
	flag = ft_help_check_swap(list, tmp, ptmp, min);
	if (flag == 1)
		if (ft_check_swap(list) == 1)
			return (0);
	return (1);
}

int		ft_min_len(t_lis **list)
{
	t_lis	*min;
	t_lis	*tmp;
	int		len;

	min = ft_find_min_ps(list);
	tmp = *list;
	len = 0;
	while (tmp != min)
	{
		len++;
		tmp = tmp->next;
	}
	return (len + 1);
}
