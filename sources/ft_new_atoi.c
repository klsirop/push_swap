/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:12:18 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/25 13:00:26 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

int			ft_print(int flag_min)
{
	if (flag_min == 1)
		return (-1);
	else
		return (0);
}

long int	ft_new_atoi(const char *str)
{
	long long int	nb;
	int				i;
	int				flag_min;

	i = 0;
	nb = 0;
	flag_min = 1;
	while ((str[i] == '\n') || (str[i] == '\v') || (str[i] == '\t')
			|| (str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
	{
		flag_min = -1;
		i++;
	}
	if ((str[i] == '+') && (flag_min != -1))
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		if (nb == (nb * 10 / 10))
			nb = nb * 10 + (int)(str[i++] - 48);
		else
			return (ft_print(flag_min));
	}
	return ((long int)nb * flag_min);
}
