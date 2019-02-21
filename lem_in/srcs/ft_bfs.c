/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:35:51 by ffahey            #+#    #+#             */
/*   Updated: 2019/02/12 12:37:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_path_set	*ft_convert_to_arr(t_ps *ps)
{
	t_path_set	*set;
	int			i;

	if (!ps)
		return (NULL);
	i = -1;
	set = (t_path_set*)malloc(sizeof(t_path_set));
	set->num_of_paths = ft_num_paths(ps);
	set->paths = (t_path**)malloc(sizeof(t_path*) * set->num_of_paths);
	set->lens = (size_t*)malloc(sizeof(size_t) * set->num_of_paths);
	set->ants = (size_t*)malloc(sizeof(size_t) * set->num_of_paths);
	while (++i < (int)set->num_of_paths)
	{
		set->paths[i] = ps->path;
		set->lens[i] = ft_path_len(ps->path);
		set->ants[i] = 0;
		ps = ps->next;
	}
	return (set);
}

static void			ft_bfs(t_path **room_queue, t_ps **path_queue,
		t_ps **result, int max_len)
{
	t_room	*room;
	t_path	*path;
	int		i;

	i = -1;
	path = ft_pop_path_line(path_queue);
	room = ft_pop_path(room_queue);
	path = ft_complete_path(path, room);
	if (!(ft_check_path(path, room->id)) ||
			(int)ft_path_len(path) - 1 > max_len)
	{
		ft_path_destroyer(&path);
		return ;
	}
	if (room->state == END_ROOM)
	{
		*result = ft_new_path(*result, path);
		return ;
	}
	while (++i < room->degree)
	{
		*room_queue = ft_complete_path(*room_queue, room->links[i]);
		*path_queue = ft_new_path(*path_queue, ft_copy_path(path));
	}
	ft_path_destroyer(&path);
}

static int			ft_max_len(t_ps *result, int ac)
{
	int		num_of_paths;
	int		max_len;
	int		i;
	t_ps	*tmp;
	int		len_sum;

	if (!result)
		return (9999);
	tmp = result;
	i = 0;
	num_of_paths = ft_num_paths(result);
	len_sum = 0;
	while (i < num_of_paths)
	{
		len_sum += ft_path_len(result->path) - 1;
		result = result->next;
		i++;
	}
	result = tmp;
	max_len = ((len_sum + ac - num_of_paths) / num_of_paths) *
		(num_of_paths + 1) - ac - len_sum + (num_of_paths + 1);
	return (max_len);
}

t_path_set			*ft_convert_set(t_path_set *set, t_ps *result, t_farm *farm,
		int nop)
{
	set = ft_convert_to_arr(result);
	if (set)
		set->ants_count = farm->ants_count;
	set = find_paths(farm->ants_count, set, nop, farm);
	return (set);
}

t_path_set			*ft_start_bfs(t_farm *farm, int nop)
{
	t_ps		*pq;
	t_path		*queue;
	int			min_paths;
	t_ps		*result;
	t_path_set	*set;

	pq = NULL;
	queue = NULL;
	result = NULL;
	queue = ft_complete_path(queue, ft_find_room(farm->rooms, farm->start));
	min_paths = 1;
	while (queue)
	{
		ft_bfs(&queue, &pq, &result, ft_max_len(result, farm->ants_count));
		if ((int)ft_num_paths(result) == min_paths)
		{
			set = ft_convert_set(set, result, farm, nop);
			if ((int)set->num_of_paths >= nop)
				return (ft_bfs_destroyer(queue, pq, result, set));
			else
				min_paths += ft_free_set(&set, 1);
		}
	}
	set = ft_convert_set(set, result, farm, 0);
	return (ft_bfs_destroyer(queue, pq, result, set));
}
