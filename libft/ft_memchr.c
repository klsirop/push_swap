/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:21:25 by volyvar-          #+#    #+#             */
/*   Updated: 2018/12/15 19:17:42 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new;
	unsigned char	c_new;

	new = (unsigned char *)s;
	c_new = (unsigned char)c;
	while (n--)
	{
		if (*new == c_new)
			return ((void *)new);
		new++;
	}
	return (NULL);
}
