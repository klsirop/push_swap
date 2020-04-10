/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:36:29 by volyvar-          #+#    #+#             */
/*   Updated: 2018/12/15 22:17:56 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_print(int flag_min)
{
	if (flag_min == 1)
		return (-1);
	else
		return (0);
}

int				ft_atoi(const char *str)
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
	return ((int)nb * flag_min);
}
