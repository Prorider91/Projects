/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:35:46 by marvin            #+#    #+#             */
/*   Updated: 2019/02/11 13:54:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path		*ft_copy_path(t_path *path)
{
	t_path	*new_path;

	new_path = NULL;
	while (path)
	{
		new_path = ft_complete_path(new_path, path->room);
		path = path->next;
	}
	return (new_path);
}

int			ft_check_path(t_path *path, int id)
{
	t_path	*head;
	int		res;

	res = 1;
	head = path;
	while (path->next)
	{
		if (path->room->id == id)
			res = 0;
		path = path->next;
	}
	path = head;
	return (res);
}

size_t		ft_num_paths(t_ps *ps)
{
	size_t	len;

	len = 0;
	while (ps)
	{
		len++;
		ps = ps->next;
	}
	return (len);
}

size_t		ft_path_len(t_path *path)
{
	size_t	len;

	len = 0;
	while (path)
	{
		len++;
		path = path->next;
	}
	return (len);
}
