/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:35:45 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/31 12:31:07 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

int		ft_add_to_list(char *str, t_lis **list, t_lis **head)
{
	if (!(list && *list))
	{
		if (!(*list = (t_lis *)malloc(sizeof(t_lis))))
			return (-1);
		(*list)->el = ft_atoi(str);
		(*list)->next = NULL;
		*head = *list;
	}
	else
	{
		if (!((*list)->next = (t_lis *)malloc(sizeof(t_lis))))
			return (-1);
		(*list) = (*list)->next;
		(*list)->el = ft_atoi(str);
		(*list)->next = NULL;
	}
	return (0);
}

int		ft_check_arg(char *str)
{
	int			i;
	long int	num;
	int			min;

	i = 0;
	min = 0;
	while (str && str[i] != '\0')
	{
		if ((i != 0) && (str[i] == '-'))
			return (-1);
		if (!(((str[i] >= '0') && (str[i] <= '9')) || (str[i] == '-')))
			return (-1);
		if ((i == 0) && (str[i] == '-'))
			min = 1;
		i++;
	}
	num = ft_new_atoi(str);
	if (((num == -1) && (min == 0)) || ((num == 0) && (min == 1)))
		return (-1);
	if ((num > 2147483647) || (num < -2147483648))
	{
		return (-1);
	}
	return (0);
}

int		ft_check_repeat(char **argv, int i)
{
	int ii;

	ii = 1;
	while (ii < i)
	{
		if (ft_atoi(argv[ii]) == ft_atoi(argv[i]))
			return (-1);
		ii++;
	}
	return (0);
}

int		ft_check_repeat_new(t_lis *head, char *str)
{
	t_lis	*tmp;
	int		num;

	if (head)
	{
		tmp = head;
		num = ft_atoi(str);
		while (tmp)
		{
			if (num == tmp->el)
				return (-1);
			tmp = tmp->next;
		}
	}
	return (0);
}

int		ft_space(char *str)
{
	int i;

	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
