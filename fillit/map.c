/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:07:42 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/11 20:38:58 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	line_to_str(char *str, unsigned short line, size_t n)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (line % 2)
			str[i] = FILL + n;
		line >>= 1;
		i++;
	}
}

void	add_tetris_to_map(char **map, t_tetris tetris)
{
	size_t			i;
	static	size_t	n;

	i = 0;
	while (*((uint16_t*)&tetris.cur_val + i) && i < 4)
	{
		line_to_str(map[i + tetris.map_row],
				*((uint16_t*)&tetris.cur_val + i), n);
		i++;
	}
	n++;
}

char	**map_init(size_t size)
{
	char	**map;
	size_t	i;
	size_t	j;

	map = (char**)malloc((size + 1) * sizeof(char*) +
			(size) * (size + 1) * sizeof(char) + 1);
	if (!map)
		return (NULL);
	map[0] = (char*)(map + size + 1);
	i = 0;
	while (++i < size)
		map[i] = map[0] + i * (size + 1);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			map[i][j] = '.';
		map[i][size] = '\n';
	}
	map[size] = NULL;
	map[size - 1][size + 1] = '\0';
	return (map);
}

void	print_my_map(t_tetris *tetris, size_t size)
{
	char	**map;
	size_t	i;

	if (!(map = map_init(size)))
		exit(1);
	i = 0;
	while (tetris[i].value)
		add_tetris_to_map(map, tetris[i++]);
	ft_putstr(map[0]);
	free(map);
}
