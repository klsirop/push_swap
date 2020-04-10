/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:10:33 by volyvar-          #+#    #+#             */
/*   Updated: 2018/12/11 18:48:15 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		len;
	char	*new;

	len = 0;
	if (s)
	{
		while (s[len] != '\0')
			len++;
	}
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new && s)
	{
		i = 0;
		while (s[i] != '\0')
		{
			if (f)
				new[i] = f(s[i]);
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
