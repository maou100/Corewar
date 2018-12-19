/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 18:59:02 by feedme            #+#    #+#             */
/*   Updated: 2018/05/05 18:24:30 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*head;
	t_list		*list;

	if (lst == NULL)
		return (NULL);
	list = f(lst);
	head = list;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if ((list->next = f(lst)) == NULL)
		{
			free(list->next);
			return (NULL);
		}
		list = list->next;
	}
	return (head);
}
