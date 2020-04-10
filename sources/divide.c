/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:58:32 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/31 12:43:41 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

static	int		ft_find_words(char const *s, char c)
{
	int		words;
	int		i;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (((char)s[i] == c) && (s[i] != '\0'))
			i++;
		if (((char)s[i] != c) && (s[i] != '\0'))
		{
			while (((char)s[i] != c) && (s[i] != '\0'))
				i++;
			words++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (words);
}

static	int		ft_find_len(const char *s, int word, char c)
{
	int		i;
	int		w;
	int		j;

	w = 0;
	i = 0;
	while (w < word)
	{
		while ((char)s[i] == c)
			i++;
		if ((char)s[i] != c)
		{
			if (w == word - 1)
				j = i;
			while (((char)s[i] != c) && (s[i] != '\0'))
				i++;
			w++;
		}
	}
	return (i - j + 1);
}

int				ft_find_slovo(char **arr, char const *s, int word, char c)
{
	int		i;
	int		w;
	int		j;

	if (!(*arr = (char *)malloc(sizeof(char) * ft_find_len(s, word, c))))
		return (-1);
	if (*arr)
	{
		w = 1;
		i = 0;
		while ((s[i] != '\0') && (w <= word))
		{
			while (((char)s[i] == c) && (s[i] != '\0'))
				i++;
			while (((char)s[i] != c) && (s[i] != '\0') && (w < word))
				i++;
			w++;
		}
		j = 0;
		while (j < ft_find_len(s, word, c) - 1)
			(*arr)[j++] = s[i++];
		(*arr)[j] = '\0';
	}
	return (0);
}

void			ft_clean(char **arr)
{
	int i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
}

char			**ft_divide(char const *s, char c)
{
	char	**arr;
	int		i;

	if (s)
		if (!(arr = (char **)malloc(sizeof(char *) *
			(ft_find_words(s, c) + 1))))
			return (NULL);
	if (s && arr)
	{
		i = 0;
		while (i < ft_find_words(s, c))
		{
			if (ft_find_slovo(&(arr[i]), s, i + 1, c) == -1)
			{
				ft_clean(arr);
				free(arr);
				arr = NULL;
				return (NULL);
			}
			i++;
		}
		arr[i] = NULL;
	}
	return (arr);
}
