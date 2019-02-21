/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:20:07 by ffahey            #+#    #+#             */
/*   Updated: 2019/02/12 12:36:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_solver(t_farm *farm)
{
	int			num_of_paths;
	t_room		*start;
	t_room		*end;
	t_path_set	*set;

	set = NULL;
	start = ft_find_room(farm->rooms, farm->start);
	end = ft_find_room(farm->rooms, farm->end);
	num_of_paths = ft_min_int(ft_min_int((int)farm->ants_count, start->degree),
			end->degree);
	set = ft_start_bfs(farm, num_of_paths);
	if (!set)
		ft_error_output(farm, "No possible solutions");
	ft_free_set(&set, 1);
}

int		main(void)
{
	t_farm		*farm;

	farm = NULL;
	farm = ft_init_farm();
	ft_print_farm_structure(farm);
	ft_putendl_fd("Initialization of farm ... OK", farm->log_fd);
	ft_solver(farm);
	ft_putendl_fd("All ants in the END room", farm->log_fd);
	ft_farm_destroyer(farm);
	return (0);
}
