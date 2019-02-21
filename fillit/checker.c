/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:14:05 by nkertzma          #+#    #+#             */
/*   Updated: 2018/12/11 14:45:17 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_connect(char *str, int index)
{
	int		count;

	count = 0;
	if (index % 5 != 0)
		if (str[index - 1] == '#')
			count++;
	if (index % 5 != 3)
		if (str[index + 1] == '#')
			count++;
	if (index > 4)
		if (str[index - 5] == '#')
			count++;
	if (index < 14)
		if (str[index + 5] == '#')
			count++;
	return (count);
}

void	check_count(char *str, int grid, int count, int i)
{
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (str[i] == '#')
			{
				count += check_connect(str, i);
				grid++;
			}
			if (str[i] == '#' && grid > 4)
				handle_error(ERROR);
			else if (str[i] != '#' && str[i] != '.')
				handle_error(ERROR);
		}
		else if (str[i] != '\n')
			handle_error(ERROR);
		i++;
	}
	if (count != 6 && count != 8)
		handle_error(ERROR);
}

void	check_piece(char *str, int ret)
{
	int		grid;
	int		count;
	int		i;

	grid = 0;
	count = 0;
	i = 0;
	if (ret < 20)
		handle_error(ERROR);
	if (ret == 21 && str[20] != '\n')
		handle_error(ERROR);
	check_count(str, grid, count, i);
}
