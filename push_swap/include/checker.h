/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:43:11 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/26 15:20:45 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define OUT_OF_MEMORY (-1)

# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define NORMAL "\033[0m"

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>

# define DEBUG_FLAG 0x01
# define COLOR_FLAG 0x02

typedef struct	s_stack
{
	int		*data;
	size_t	size;
	int		top;
	char	flags;
	int		index1;
	int		index2;
}				t_stack;

typedef char	*(*t_command_function)(t_stack *a, t_stack *b);

char			*ft_sa(t_stack *a, t_stack *b);
char			*ft_sb(t_stack *a, t_stack *b);
char			*ft_ss(t_stack *a, t_stack *b);
char			*ft_pa(t_stack *a, t_stack *b);
char			*ft_pb(t_stack *a, t_stack *b);
char			*ft_ra(t_stack *a, t_stack *b);
char			*ft_rb(t_stack *a, t_stack *b);
char			*ft_rr(t_stack *a, t_stack *b);
char			*ft_rra(t_stack *a, t_stack *b);
char			*ft_rrb(t_stack *a, t_stack *b);
char			*ft_rrr(t_stack *a, t_stack *b);

t_stack			*ft_stk_create(size_t size, char flags);
void			ft_stk_delete(t_stack *stack);
int				ft_init_stacks(t_stack **a, t_stack **b, int ac, char **av);
void			ft_print_stack(t_stack *a, t_stack *b);

void			ft_apply_command(t_stack *a, t_stack *b, char *command);

#endif
