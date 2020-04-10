/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:06:08 by volyvar-          #+#    #+#             */
/*   Updated: 2018/12/10 16:49:39 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		save_i;

	i = 0;
	if ((haystack[i] == '\0') && (needle[i] == '\0'))
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		if ((haystack[i] == needle[j]) || (needle[j] == '\0'))
		{
			save_i = i;
			while ((needle[j] != '\0') && (haystack[i] == needle[j]))
			{
				j++;
				i++;
			}
			if (needle[j] == '\0')
				return ((char *)(haystack + save_i));
			i = save_i;
		}
		i++;
	}
	return (NULL);
}
