/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:51:47 by marvin            #+#    #+#             */
/*   Updated: 2019/02/11 14:03:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_path_destroyer(t_path **path)
{
	t_path	*tmp;

	while (path && *path)
	{
		tmp = (*path)->next;
		free(*path);
		*path = tmp;
	}
}

void		ft_ps_destroyer(t_ps **ps, char mod)
{
	t_ps	*tmp;

	while (ps && *ps)
	{
		tmp = (*ps)->next;
		if (mod)
			ft_path_destroyer(&((*ps)->path));
		free(*ps);
		*ps = tmp;
	}
}

t_path_set	*ft_bfs_destroyer(t_path *room_queue, t_ps *path_queue,
		t_ps *result, t_path_set *set)
{
	ft_path_destroyer(&room_queue);
	ft_ps_destroyer(&path_queue, 1);
	ft_ps_destroyer(&result, 1);
	return (set);
}

int			*ft_recursion_complete(int *res2, t_path_set *set, int *res)
{
	if (total_path_len(res2, set->ants_count, set->lens) <
			total_path_len(res, set->ants_count, set->lens))
	{
		free(res);
		res = res2;
	}
	return (res2);
}
