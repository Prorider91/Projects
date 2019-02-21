/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:43:04 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/12 14:49:50 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define SIZE 26
# define FILL 'A'
# define USAGE 1
# define ERROR 2

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include <string.h>
# include "libft.h"

typedef struct			s_tetris
{
	uint64_t			value;
	uint64_t			cur_val;
	size_t				map_row;
}						t_tetris;

typedef struct			s_limits
{
	unsigned short		x_max;
	size_t				y_max;
}						t_limits;

int						fill_pieces(int fd, t_tetris *tetris);
void					check_piece(char *str, int ret);
size_t					solver(t_tetris *tetris);
void					print_my_map(t_tetris *tetris, size_t size);
int						handle_error(int flag);

#endif
