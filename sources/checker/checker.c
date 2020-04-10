/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:46:54 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/31 18:00:24 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

int		main(int argc, char **argv)
{
	t_lis	*list;
	t_lis	*help;
	int		flag;
	int		tmp;

	flag = 0;
	list = NULL;
	help = NULL;
	if (argc == 1)
		return (0);
	tmp = ft_valid_arg_ch(argc, argv, &list, &flag);
	if (tmp == -1)
		return (ft_error(&list, &help));
	if (tmp == 3)
		return (0);
	if (ft_valid_command(&list, &help, &flag) == -1)
		return (ft_error(&list, &help));
	ft_is_sorted(&list, &help);
	ft_delete_list(&list);
	ft_delete_list(&help);
	return (0);
}
