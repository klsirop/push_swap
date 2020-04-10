/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:51:57 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/31 17:41:43 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

int		ft_find_mas(char ***mas, char **argv, int i)
{
	if ((*mas = ft_divide(argv[i], ' ')) == NULL)
	{
		if (argv[i] == 0 || ft_space(argv[i]) == 1)
			return (0);
		return (-1);
	}
	return (1);
}

void	ft_free_mas(char **arr)
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

int		ft_help_valid_arg(int *tmp, char ***mas, t_lis **list, t_lis **head)
{
	int j;

	j = 0;
	while (*mas && ((*mas)[j] != NULL))
	{
		if ((*tmp == -1) || (ft_check_arg((*mas)[j]) == -1) ||
			(ft_check_repeat_new(*head, (*mas)[j]) == -1) ||
			(ft_add_to_list((*mas)[j], list, head) == -1))
		{
			ft_free_mas(*mas);
			free(*mas);
			*mas = NULL;
			*list = *head;
			return (-1);
		}
		j++;
	}
	return (0);
}

int		ft_valid_arg_h(int *i, int *flag, char **argv, int argc)
{
	int f;

	f = 0;
	while ((*i < argc) && ((*i == 1) || ((*i == 2) && (*flag != 0))))
	{
		f = ft_find_flag(*i, argv, flag);
		if (f == -1)
			return (-1);
		if (f == 1)
			(*i)++;
		else
			break ;
	}
	if (*i >= argc)
		return (3);
	return (0);
}

int		ft_valid_arg_ch(int argc, char **argv, t_lis **list, int *flag)
{
	int		i;
	t_lis	*head;
	char	**mas;
	int		tmp;

	ft_init_val(&i, &mas, &head);
	while (i < argc)
	{
		tmp = ft_valid_arg_h(&i, flag, argv, argc);
		if (tmp != 0)
			return (tmp);
		if (((tmp = ft_find_mas(&mas, argv, i)) == -1) ||
			(ft_help_valid_arg(&tmp, &mas, list, &head) == -1))
			return (-1);
		ft_free_mas(mas);
		free(mas);
		mas = NULL;
		i++;
	}
	*list = head;
	if (*list == NULL)
		return (-1);
	return (0);
}
