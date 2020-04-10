/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:01:19 by volyvar-          #+#    #+#             */
/*   Updated: 2018/12/15 18:37:37 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int			ft_get_len(int n)
{
	int		len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static	char		*ft_fill(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 12);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

static void			ft_clean_str(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = '\0';
		i++;
	}
}

char				*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		return (ft_fill());
	len = ft_get_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str)
	{
		ft_clean_str(str);
		if (n < 0)
		{
			n *= -1;
			str[0] = '-';
		}
		str[len] = '\0';
		len -= 1;
		while ((len != -1) && (str[len] != '-'))
		{
			str[len] = n % 10 + 48;
			n /= 10;
			len--;
		}
	}
	return (str);
}
