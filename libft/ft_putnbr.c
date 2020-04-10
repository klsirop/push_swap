/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:11:19 by volyvar-          #+#    #+#             */
/*   Updated: 2018/12/10 16:46:55 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_pow(int n, int i, int len)
{
	int		j;

	j = 1;
	while (j <= len - i)
	{
		n /= 10;
		j++;
	}
	return (n % 10);
}

static	int			ft_get_len_1(int n)
{
	int		len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

void				ft_putnbr(int n)
{
	int		len;
	int		new;
	int		i;

	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	if (n == 0)
		ft_putchar('0');
	if (n > 0)
	{
		len = ft_get_len_1(n);
		i = 1;
		while (i <= len)
		{
			new = ft_pow(n, i, len);
			ft_putchar(new + 48);
			i++;
		}
	}
}
