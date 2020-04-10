/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:17:01 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/26 17:05:08 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

int		ft_create_arr(t_lis **list, int **arr)
{
	int		len;
	int		i;
	t_lis	*tmp;

	len = ft_find_list_len(list);
	if (!(*arr = (int *)malloc(sizeof(int) * len)))
		return (-1);
	tmp = *list;
	i = 0;
	while (tmp)
	{
		(*arr)[i] = tmp->el;
		tmp = tmp->next;
		i++;
	}
	return (len);
}

int		ft_find_median(t_lis **list, int *median)
{
	int *arr;
	int len;

	if ((len = ft_create_arr(list, &arr)) == -1)
		return (-1);
	*median = arr[len / 2];
	free(arr);
	arr = NULL;
	return (0);
}
