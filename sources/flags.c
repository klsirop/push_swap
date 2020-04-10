/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:21:03 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/31 12:42:23 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

int		ft_valid_arg_ps(int argc, char **argv, t_lis **list)
{
	int		i;
	t_lis	*head;
	char	**mas;
	int		tmp;

	i = 1;
	mas = NULL;
	head = NULL;
	while (i < argc)
	{
		tmp = ft_find_mas(&mas, argv, i);
		if (ft_help_valid_arg(&tmp, &mas, list, &head) == -1)
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

int		ft_find_flags_h(int *flag, int i)
{
	if (*flag != 2)
	{
		if (i == 1)
			*flag = 2;
		else if (*flag == 1)
			*flag = 3;
		else
			return (-1);
		return (1);
	}
	else
		return (-1);
}

int		ft_find_flag(int i, char **argv, int *flag)
{
	if (ft_strcmp(argv[i], "-v") == 0)
	{
		if (*flag != 1)
		{
			if (i == 1)
				*flag = 1;
			else if (*flag == 2)
				*flag = 3;
			else
				return (-1);
			return (1);
		}
		else
			return (-1);
	}
	else if (ft_strcmp(argv[i], "-c") == 0)
		return (ft_find_flags_h(flag, i));
	else
		return (0);
}
