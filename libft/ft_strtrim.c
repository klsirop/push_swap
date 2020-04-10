/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:03:44 by volyvar-          #+#    #+#             */
/*   Updated: 2018/12/10 16:40:07 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_getlen(char const *s)
{
	int		i;
	int		j;
	int		origin;

	origin = ft_strlen(s);
	i = 0;
	while ((i < origin) && ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t')))
		i++;
	j = origin - 1;
	while ((j >= 0) && ((s[j] == ' ') || (s[j] == '\n') || (s[j] == '\t')))
		j--;
	if (i == origin)
		return (0);
	return (j - i + 1);
}

static char		*ft_while(char const *s, char *new, int len)
{
	int		i;
	int		j;

	i = 0;
	while ((s[i] != '\0') && ((s[i] == ' ') ||
				(s[i] == '\n') || (s[i] == '\t')))
		i++;
	len = len + i;
	j = 0;
	while (i < len)
	{
		new[j] = s[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}

char			*ft_strtrim(char const *s)
{
	int		len;
	char	*new;

	if (s)
	{
		len = ft_getlen(s);
		new = (char *)malloc(sizeof(char) * (len + 1));
	}
	else
		new = NULL;
	if (new && s)
	{
		new = ft_while(s, new, len);
	}
	return (new);
}
