/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:22:27 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/31 17:40:49 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

int		get_next_line_wb(const int fd, char **line)
{
	int			tr;
	static char	*rem2;
	char		*tmp;

	tmp = NULL;
	if ((fd < 0) || (!line) || (BUFF_SIZE <= 0) || (read(fd, tmp, 0) < 0))
		return (-1);
	free(tmp);
	tr = -2;
	if (ft_find_line(&rem2, &tr, fd) == -1)
		return (-1);
	return (ft_get_line(tr, &(rem2), line));
}

void	ft_init_val(int *i, char ***mas, t_lis **head)
{
	*i = 1;
	*mas = NULL;
	*head = NULL;
}
