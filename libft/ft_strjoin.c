/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 18:44:18 by volyvar-          #+#    #+#             */
/*   Updated: 2018/12/10 16:39:27 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*ft_while_new(char const *s2, char *new, int i, int len2)
{
	int		j;

	j = 0;
	while (i < len2)
	{
		new[i] = s2[j];
		j++;
		i++;
	}
	new[i] = '\0';
	return (new);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*new;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		new = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	}
	else
		new = NULL;
	if (new && s1 && s2)
	{
		i = 0;
		while (i < len1)
		{
			new[i] = s1[i];
			i++;
		}
		len2 += len1;
		new = ft_while_new(s2, new, i, len2);
	}
	return (new);
}
