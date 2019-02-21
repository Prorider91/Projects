/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:59:38 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/11 20:02:09 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_margin(t_tetris tetris, t_limits limits)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (*((unsigned short*)&tetris.cur_val + i) & limits.x_max)
			return (1);
		i++;
	}
	return (0);
}

void	move_tetris(t_tetris *tetris, t_limits *limits)
{
	tetris->cur_val <<= 1;
	if (check_margin(*tetris, *limits))
	{
		tetris->cur_val = tetris->value;
		tetris->map_row += 1;
	}
}

int		help_solver(t_tetris *tetris, uint16_t *map, t_limits *limits)
{
	tetris->cur_val = tetris->value;
	tetris->map_row = 0;
	while (tetris->value)
	{
		if (tetris->cur_val & *((uint64_t*)(map + tetris->map_row)))
			move_tetris(tetris, limits);
		else
		{
			*((uint64_t*)(map + tetris->map_row)) |= tetris->cur_val;
			if (map[limits->y_max] || check_margin(*tetris, *limits))
			{
				*((uint64_t*)(map + tetris->map_row)) ^= tetris->cur_val;
				return (0);
			}
			if (help_solver(tetris + 1, map, limits))
				return (1);
			else
			{
				*((uint64_t*)(map + tetris->map_row)) ^= tetris->cur_val;
				move_tetris(tetris, limits);
			}
		}
	}
	return (1);
}

size_t	solver(t_tetris *tetris)
{
	uint16_t	map[16];
	int			res;
	size_t		z;
	t_limits	limits;

	limits.y_max = 0;
	limits.x_max = 1;
	res = 0;
	while (!res)
	{
		limits.y_max++;
		if (limits.y_max >= 16)
			return (0);
		limits.x_max <<= 1;
		z = 16;
		while (z--)
			map[z] = 0;
		res = help_solver(tetris, map, &limits);
	}
	return (limits.y_max);
}
