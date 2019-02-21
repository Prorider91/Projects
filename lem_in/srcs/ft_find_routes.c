/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_routes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:45:03 by ffahey            #+#    #+#             */
/*   Updated: 2019/02/12 12:36:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		free_matrix(unsigned char **cross_m, size_t num)
{
	size_t i;

	i = 0;
	while (i < num)
	{
		free(cross_m[i]);
		i++;
	}
	free(cross_m);
}

static void		clear_all(unsigned char **matrix, t_path_set *set,
							int *best, size_t path_num)
{
	free_matrix(matrix, path_num);
	ft_free_set(&set, 0);
	free(best);
}

static int		find_num(int *best)
{
	int i;

	i = 0;
	while (best[i] != -1)
		i++;
	return (i);
}

static void		ft_set_to_res(t_path_set *set, t_path_set *res, int *best)
{
	size_t	j;

	j = 0;
	while (j < res->num_of_paths)
	{
		res->paths[j] = ft_copy_path(set->paths[best[j]]);
		(res->lens)[j] = (set->lens)[best[j]];
		(res->ants)[j] = 0;
		j++;
		(res->paths)[j] = NULL;
	}
}

t_path_set		*find_paths(int ants_c, t_path_set *set, int nop, t_farm *f)
{
	int					*best;
	t_path_set			*res;
	unsigned char		**cross_m;

	(void)nop;
	if (!set)
		return (NULL);
	cross_m = make_cross_matrix(set->paths, set->num_of_paths);
	best = find_best_path(ants_c, set, cross_m);
	res = (t_path_set*)malloc(sizeof(t_path_set));
	res->num_of_paths = find_num(best);
	res->paths = (t_path**)malloc(sizeof(t_path*) * (res->num_of_paths + 1));
	res->lens = (size_t*)malloc(sizeof(size_t) * res->num_of_paths);
	res->ants = (size_t*)malloc(sizeof(size_t) * res->num_of_paths);
	ft_set_to_res(set, res, best);
	if ((int)res->num_of_paths >= nop)
	{
		ft_lst_print(f->output);
		move_ants(ants_c, res);
	}
	clear_all(cross_m, set, best, set->num_of_paths);
	return (res);
}
