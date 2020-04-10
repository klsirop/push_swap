/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:28:56 by volyvar-          #+#    #+#             */
/*   Updated: 2018/12/10 16:49:56 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		save_i;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while ((haystack[i] != '\0') && (i < len))
	{
		j = 0;
		save_i = i;
		while ((haystack[i] == needle[j]) && (i < len) && (needle[j] != '\0'))
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)(haystack + save_i));
		i = save_i + 1;
	}
	return (NULL);
}
