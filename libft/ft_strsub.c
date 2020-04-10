/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 18:35:22 by volyvar-          #+#    #+#             */
/*   Updated: 2018/12/10 16:37:37 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new)
	{
		if (s)
		{
			i = 0;
			len = start + len;
			while (start < len)
			{
				new[i] = s[start];
				i++;
				start++;
			}
			new[i] = '\0';
		}
	}
	return (new);
}
