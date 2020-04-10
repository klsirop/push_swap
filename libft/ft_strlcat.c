/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:12:21 by volyvar-          #+#    #+#             */
/*   Updated: 2018/12/10 19:20:33 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	ld;
	size_t	ls;

	ld = 0;
	while (dst[ld] != '\0')
		ld++;
	ls = 0;
	while (src[ls] != '\0')
		ls++;
	if (size < ld)
		return (size + ls);
	i = 0;
	while (dst[i] != '\0')
		i++;
	j = 0;
	while ((src[j] != '\0') && (i < size - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ld + ls);
}
