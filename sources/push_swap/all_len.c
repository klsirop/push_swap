/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:01:32 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/26 17:25:50 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

int		ft_tmp_hlen(t_lis **list, t_lis *find)
{
	t_lis	*tmp;
	int		len;

	tmp = *list;
	len = 0;
	while (tmp != find)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

int		ft_find_this_len(t_lis **list, t_lis **help, t_lis *find)
{
	int hlen;
	int llen;
	int ll;
	int lh;

	ll = ft_find_list_len(list);
	lh = ft_find_list_len(help);
	hlen = ft_tmp_hlen(help, find);
	if (lh - hlen < hlen)
		hlen = (lh - hlen);
	llen = ft_new_tmp_len(list, find);
	if (ll - llen < llen)
		llen = (ll - llen);
	return (hlen + llen);
}

int		ft_find_all_len(t_lis **list, t_lis **help, int **mas)
{
	int		len;
	int		i;
	t_lis	*tmp;

	len = ft_find_list_len(help);
	if (!((*mas = (int *)malloc(sizeof(int) * len))))
		return (-1);
	tmp = *help;
	i = 0;
	while (tmp)
	{
		(*mas)[i] = ft_find_this_len(list, help, tmp);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

int		ft_find_min_mas(int *mas, int len)
{
	int i;
	int min;
	int ind;

	i = 0;
	min = mas[i];
	ind = 0;
	while (i < len)
	{
		if (min > mas[i])
		{
			min = mas[i];
			ind = i;
		}
		i++;
	}
	return (ind);
}
