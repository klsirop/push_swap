/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 18:25:08 by volyvar-          #+#    #+#             */
/*   Updated: 2018/12/10 16:37:14 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (s1 && s2)
	{
		i = 0;
		while ((s1[i] != '\0') && (i < n))
		{
			if (s2[i] == '\0')
				return (0);
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		if (i == n)
			return (1);
		if ((s1[i] == '\0') && (s2[i] != '\0'))
			return (0);
		return (1);
	}
	return (0);
}
