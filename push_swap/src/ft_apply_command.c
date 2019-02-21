/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:39:41 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/24 15:47:51 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_init_command_string(char **com_str)
{
	com_str[0] = "sa";
	com_str[1] = "sb";
	com_str[2] = "ss";
	com_str[3] = "pa";
	com_str[4] = "pb";
	com_str[5] = "ra";
	com_str[6] = "rb";
	com_str[7] = "rr";
	com_str[8] = "rra";
	com_str[9] = "rrb";
	com_str[10] = "rrr";
	com_str[11] = NULL;
}

static void	ft_init_commans_func(t_command_function *com_func)
{
	com_func[0] = ft_sa;
	com_func[1] = ft_sb;
	com_func[2] = ft_ss;
	com_func[3] = ft_pa;
	com_func[4] = ft_pb;
	com_func[5] = ft_ra;
	com_func[6] = ft_rb;
	com_func[7] = ft_rr;
	com_func[8] = ft_rra;
	com_func[9] = ft_rrb;
	com_func[10] = ft_rrr;
	com_func[11] = NULL;
}

static int	ft_find_index(char *command, char **com_str)
{
	int		i;

	i = 0;
	while (com_str[i])
	{
		if (ft_strcmp(com_str[i], command) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void		ft_apply_command(t_stack *a, t_stack *b, char *command)
{
	static char					*com_str[12];
	static t_command_function	com_func[12];
	int							com_index;

	if (*com_str == NULL)
		ft_init_command_string(com_str);
	if (*com_func == NULL)
		ft_init_commans_func(com_func);
	com_index = ft_find_index(command, com_str);
	if (com_index < 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	com_func[com_index](a, b);
}
