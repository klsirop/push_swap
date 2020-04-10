/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:30:10 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/27 13:42:06 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

int		main(int argc, char **argv)
{
	t_lis	*list;
	t_lis	*help;

	list = NULL;
	help = NULL;
	if (argc == 1)
		return (0);
	if (ft_valid_arg_ps(argc, argv, &list) == -1)
		return (ft_error(&list, &help));
	if (ft_big_sort(&list, &help) == -1)
		ft_error(&list, &help);
	ft_delete_list(&list);
	ft_delete_list(&help);
	list = NULL;
	help = NULL;
	return (0);
}
