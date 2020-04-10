/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:19:51 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/31 16:37:41 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

void	ft_check_line_help(char *line, t_lis **list, t_lis **help, int *flag)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_list_swap(list);
	if (ft_strcmp(line, "sb") == 0)
		ft_list_swap(help);
	if (ft_strcmp(line, "ss") == 0)
		ft_list_swap_all(list, help);
	if (ft_strcmp(line, "pa") == 0)
		ft_list_push(list, help);
	if (ft_strcmp(line, "pb") == 0)
		ft_list_push(help, list);
	if (ft_strcmp(line, "ra") == 0)
		ft_list_rotate(list);
	if (ft_strcmp(line, "rb") == 0)
		ft_list_rotate(help);
	if (ft_strcmp(line, "rr") == 0)
		ft_list_rotate_all(list, help);
	if (ft_strcmp(line, "rra") == 0)
		ft_list_rev_rotate(list);
	if (ft_strcmp(line, "rrb") == 0)
		ft_list_rev_rotate(help);
	if (ft_strcmp(line, "rrr") == 0)
		ft_list_rev_rotate_all(list, help);
	ft_print_list(list, help, flag);
}

int		ft_check_line(char *line, t_lis **list, t_lis **help, int *flag)
{
	if (!((ft_strcmp(line, "sa") == 0) || (ft_strcmp(line, "sb") == 0) ||
		(ft_strcmp(line, "ss") == 0) || (ft_strcmp(line, "pa") == 0) ||
		(ft_strcmp(line, "pb") == 0) || (ft_strcmp(line, "ra") == 0) ||
		(ft_strcmp(line, "rb") == 0) || (ft_strcmp(line, "rr") == 0) ||
		(ft_strcmp(line, "rra") == 0) || (ft_strcmp(line, "rrb") == 0) ||
		(ft_strcmp(line, "rrr") == 0)))
		return (-1);
	ft_check_line_help(line, list, help, flag);
	return (0);
}

int		ft_valid_command(t_lis **list, t_lis **help, int *flag)
{
	int		res;
	char	*line;

	line = NULL;
	while ((res = get_next_line_wb(0, &line)) > 0)
	{
		if (ft_check_line(line, list, help, flag) == -1)
		{
			ft_strdel(&line);
			return (-1);
		}
		if (line)
			ft_strdel(&line);
	}
	if (res == -1)
		return (-1);
	return (0);
}
