/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:19:37 by volyvar-          #+#    #+#             */
/*   Updated: 2018/12/10 16:36:31 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;
	int				len;

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
				new[i] = f(i, s[i]);
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
