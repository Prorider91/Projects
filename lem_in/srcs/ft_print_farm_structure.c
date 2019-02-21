/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_farm_structure.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:50:38 by ffahey            #+#    #+#             */
/*   Updated: 2019/02/11 20:59:20 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_print_room(t_room *room, int fd)
{
	size_t	i;

	ft_putstr_fd("Room ", fd);
	ft_putendl_fd(room->name, fd);
	ft_putstr_fd("id: ", fd);
	ft_putnbr_fd(room->id, fd);
	ft_putstr_fd("\nCoords: ", fd);
	ft_putnbr_fd(room->x, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(room->y, fd);
	ft_putstr_fd("\nState: ", fd);
	ft_putnbr_fd(room->state, fd);
	ft_putstr_fd("\nLinks count: ", fd);
	ft_putnbr_fd(room->degree, fd);
	ft_putstr_fd("\nLinks: ", fd);
	i = 0;
	while (room->links && room->links[i])
	{
		ft_putstr_fd(room->links[i]->name, fd);
		ft_putchar_fd(' ', fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}

void		ft_print_farm_structure(t_farm *farm)
{
	t_room	*room;
	int		fd;

	if (!farm)
		return ;
	fd = open("farm_structure.farm", O_CREAT | O_WRONLY | O_TRUNC,
			S_IREAD | S_IWRITE);
	ft_putstr_fd("Farm structure:\n\n1. GENERAL\n", fd);
	ft_putstr_fd("\tNumber of ants: ", fd);
	ft_putnbr_fd((int)farm->ants_count, fd);
	ft_putstr_fd("\n\tNumber of rooms: ", fd);
	ft_putnbr_fd((int)farm->rooms_count, fd);
	ft_putstr_fd("\n\tStart room`s name: ", fd);
	ft_putstr_fd(farm->start, fd);
	ft_putstr_fd("\n\tEnd room`s name:", fd);
	ft_putstr_fd(farm->end, fd);
	ft_putendl_fd("\n\n2. ROOMS\n", fd);
	room = farm->rooms;
	while (room)
	{
		ft_print_room(room, fd);
		ft_putchar_fd('\n', fd);
		room = room->next;
	}
	close(fd);
}
