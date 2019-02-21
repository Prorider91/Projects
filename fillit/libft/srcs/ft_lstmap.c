/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:24:47 by ffahey            #+#    #+#             */
/*   Updated: 2018/11/28 13:38:14 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_del(void *data, size_t size)
{
	char	*ptr;

	if (data)
	{
		ptr = (char*)data;
		while (size--)
			ptr[size] = 0;
	}
}

static void		ft_reverse(t_list **begin_list)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	if (begin_list && *begin_list)
	{
		prev = NULL;
		current = *begin_list;
		next = NULL;
		while (current != NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		*begin_list = prev;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*tmp;
	t_list	*head;

	head = NULL;
	if (lst && f)
	{
		while (lst)
		{
			tmp = f(lst);
			if (!(list = ft_lstnew(tmp->content, tmp->content_size)))
			{
				ft_lstdel(&head, ft_del);
				return (NULL);
			}
			list->next = head;
			head = list;
			lst = lst->next;
		}
		ft_reverse(&head);
		return (head);
	}
	return (NULL);
}
