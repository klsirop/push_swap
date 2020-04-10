/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmemalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:03:33 by volyvar-          #+#    #+#             */
/*   Updated: 2018/12/09 20:04:23 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*tmp;
	size_t	i;

	tmp = malloc(sizeof(void) * size);
	if (tmp)
	{
		i = 0;
		while (i < size)
		{
			*((int *)(tmp + i)) = 0;
			i++;
		}
	}
	return ((void *)tmp);
}
