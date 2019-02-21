/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:22:43 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/27 18:25:04 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_del_double(t_list **list, char *s1, char *s2)
{
	t_list	*tmp;

	tmp = NULL;
	if (*list && !ft_strcmp((*list)->str, s1))
	{
		if ((*list)->next && !ft_strcmp((*list)->next->str, s2))
		{
			if ((*list)->prev == NULL)
				tmp = (*list)->next->next;
			ft_lst_del((*list)->next);
			ft_lst_del(*list);
			if (!tmp)
				*list = (*list)->prev;
			else
				*list = tmp;
			return (1);
		}
	}
	return (0);
}

static void	ft_replace(t_list *com, char *s1, char *s2)
{
	while (com && com->next)
	{
		if (!ft_strcmp(com->str, s1) &&
				!(ft_strcmp(com->next->str, s2)))
		{
			com->str[ft_strlen(s1) - 2] = s1[0];
			ft_lst_del(com->next);
		}
		com = com->next;
	}
}

static void	ft_replace_all(t_list **head)
{
	t_list	*list;
	int		res;

	list = *head;
	while (list && list->next)
	{
		res = 0;
		res += ft_del_double(&list, "sa\n", "sa\n");
		res += ft_del_double(&list, "sb\n", "sb\n");
		res += ft_del_double(&list, "pa\n", "pb\n");
		res += ft_del_double(&list, "pb\n", "pa\n");
		res += ft_del_double(&list, "ra\n", "rra\n");
		res += ft_del_double(&list, "rra\n", "ra\n");
		res += ft_del_double(&list, "rb\n", "rrb\n");
		res += ft_del_double(&list, "rrb\n", "rb\n");
		res += ft_del_double(&list, "rr\n", "rrr\n");
		res += ft_del_double(&list, "rrr\n", "rr\n");
		res += ft_del_double(&list, "ss\n", "ss\n");
		if (res == 0)
			list = list->next;
	}
	while (list && list->prev)
		list = list->prev;
	*head = list;
}

void		ft_command_optimization1(t_list **head)
{
	ft_replace(*head, "sa\n", "sb\n");
	ft_replace(*head, "sb\n", "sa\n");
	ft_replace(*head, "ra\n", "rb\n");
	ft_replace(*head, "rb\n", "ra\n");
	ft_replace(*head, "rra\n", "rrb\n");
	ft_replace(*head, "rrb\n", "rra\n");
	ft_replace_all(head);
}
