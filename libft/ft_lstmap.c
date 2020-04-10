/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:18:42 by volyvar-          #+#    #+#             */
/*   Updated: 2018/12/14 19:12:55 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_clean(t_list *head)
{
	t_list *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *tmp;

	head = NULL;
	while (lst && f)
	{
		tmp = ft_lstnew(f(lst)->content, f(lst)->content_size);
		if (!tmp)
			return (NULL);
		lst = lst->next;
		head = tmp;
		while (lst)
		{
			tmp->next = ft_lstnew((f(lst)->content), (f(lst))->content_size);
			if (!tmp)
			{
				ft_clean(head);
				return (NULL);
			}
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (head);
}
