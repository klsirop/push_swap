/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 12:44:23 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/25 16:42:29 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

int		ft_abs(int a)
{
	if (a >= 0)
		return (a);
	else
	{
		return (-a);
	}
}

void	ft_new_tmp_len_1(t_lis **tmp, t_lis *find, int *len, int *flag)
{
	while ((*tmp) && ((*tmp)->el > find->el))
	{
		*flag = 1;
		if (((*tmp)->next) && ((*tmp)->el) > ((*tmp)->next)->el)
		{
			(*len)++;
			*tmp = (*tmp)->next;
			break ;
		}
		(*len)++;
		*tmp = (*tmp)->next;
	}
}

int		ft_new_tmp_len_2(t_lis **tmp, int *len, t_lis **list, t_lis *find)
{
	while ((*tmp) && (find->el > (*tmp)->el) && ft_break(list))
	{
		if (((*tmp)->next) && ((*tmp)->el) > ((*tmp)->next)->el)
		{
			(*len)++;
			*tmp = (*tmp)->next;
			return (1);
		}
		(*len)++;
		*tmp = (*tmp)->next;
	}
	return (0);
}

void	ft_new_tmp_len_3(t_lis **tmp, int *len, t_lis *find)
{
	if (*tmp)
	{
		while (*tmp)
		{
			if (((*tmp)->el > find->el) || (((*tmp)->next) &&
				((*tmp)->el) > ((*tmp)->next)->el))
			{
				if (((*tmp)->next) && (((*tmp)->el) > ((*tmp)->next)->el) &&
					(find->el < ((*tmp)->next)->el))
					(*len)++;
				break ;
			}
			(*len)++;
			*tmp = (*tmp)->next;
		}
	}
	else
		*len = 0;
}

int		ft_new_tmp_len(t_lis **list, t_lis *find)
{
	t_lis	*tmp;
	int		len;
	int		flag;

	len = 0;
	tmp = *list;
	flag = 0;
	ft_new_tmp_len_1(&tmp, find, &len, &flag);
	if (flag != -1)
	{
		if (ft_new_tmp_len_2(&tmp, &len, list, find) == 1)
			return (len);
	}
	ft_new_tmp_len_3(&tmp, &len, find);
	return (len);
}
