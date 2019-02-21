/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:15:09 by nkertzma          #+#    #+#             */
/*   Updated: 2018/12/11 14:44:37 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		handle_error(int flag)
{
	if (flag == USAGE)
	{
		ft_putendl("Usage: ./fillit file_with_tetriminos");
		ft_putstr("Your file should contain between 1 and 26 tetriminos");
		ft_putendl(", separated by a line break");
	}
	else if (flag == ERROR)
		ft_putendl("error");
	exit(1);
}

int		main(int ac, char **av)
{
	t_tetris	tetris[SIZE];
	size_t		size;
	int			count;
	int			fd;

	if (ac != 2)
		handle_error(USAGE);
	if ((fd = open(av[1], 'r')) < 0)
		handle_error(ERROR);
	count = fill_pieces(fd, tetris);
	if (count < 1 || count > 26)
		handle_error(ERROR);
	if (!(size = solver(tetris)))
		handle_error(ERROR);
	print_my_map(tetris, size);
	close(fd);
	return (0);
}
