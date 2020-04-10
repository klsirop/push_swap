/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:02:38 by volyvar-          #+#    #+#             */
/*   Updated: 2018/12/10 16:47:34 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_pow1(int n, int i, int len)
{
	int j;

	j = 1;
	while (j <= len - i)
	{
		n /= 10;
		j++;
	}
	return (n % 10);
}

static	int			ft_get_len_11(int n)
{
	int len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void				ft_putnbr_fd(int n, int fd)
{
	int		len;
	int		new;
	int		i;

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n > 0)
	{
		len = ft_get_len_11(n);
		i = 1;
		while (i <= len)
		{
			new = ft_pow1(n, i, len);
			ft_putchar_fd(new + 48, fd);
			i++;
		}
	}
}
