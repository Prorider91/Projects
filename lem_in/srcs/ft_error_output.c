/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:28:00 by ffahey            #+#    #+#             */
/*   Updated: 2019/02/12 12:10:23 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_lst_print_fd(t_list *list, int fd)
{
	if (list)
	{
		while (list && list->next)
			list = list->next;
		while (list && list->prev)
		{
			ft_putendl_fd(list->str, fd);
			list = list->prev;
		}
		ft_putstr_fd(list->str, fd);
	}
}

void		ft_error_output(t_farm *farm, const char *error_message)
{
	t_list	*head;

	head = farm->output;
	ft_putstr("ERROR\n");
	ft_lst_print_fd(farm->output, farm->log_fd);
	ft_putstr_fd("\t\tError: ", farm->log_fd);
	ft_putendl_fd(error_message, farm->log_fd);
	close(farm->log_fd);
	ft_farm_destroyer(farm);
	exit(0);
}
