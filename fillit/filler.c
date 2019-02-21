/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:22:44 by nkertzma          #+#    #+#             */
/*   Updated: 2018/12/11 20:38:31 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	fill_piece(char *str)
{
	t_tetris	tetris;
	int			i;
	int			j;
	char		tmp[4];

	i = 0;
	while (i < 4)
	{
		j = -1;
		while (str[++j] != '\n')
			tmp[j] = str[j] == '#' ? 1 : 0;
		str += j + 1;
		*((uint16_t*)&tetris.cur_val + i) =
			tmp[0] + tmp[1] * 2 + tmp[2] * 4 + tmp[3] * 8;
		i++;
	}
	tetris.value = tetris.cur_val;
	tetris.map_row = 0;
	return (tetris);
}

void		replace_tetris(t_tetris *tetris)
{
	size_t			i;
	uint64_t		check;
	unsigned short	*p_check;

	p_check = (unsigned short*)&check;
	i = 0;
	while (i < 4)
	{
		p_check[i] = 1;
		i++;
	}
	while (!(check & tetris->cur_val))
		tetris->cur_val >>= 1;
	while (((uint16_t)tetris->cur_val) == 0)
		tetris->cur_val >>= 16;
	tetris->value = tetris->cur_val;
}

int			fill_pieces(int fd, t_tetris *tetris)
{
	char	buf[22];
	int		ret;
	int		cret;
	int		i;

	i = 0;
	ft_bzero(buf, 22);
	while ((ret = read(fd, buf, 21)))
	{
		check_piece(buf, ret);
		tetris[i] = fill_piece(buf);
		replace_tetris(tetris + i);
		cret = ret;
		i++;
	}
	if (cret == 21)
		handle_error(ERROR);
	return (i);
}
