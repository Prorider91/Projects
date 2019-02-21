/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:44:31 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/27 16:34:45 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX(a, b) a > b ? a : b
# define MIN(a, b) a < b ? a : b
# define C(a) printf("Check%d\n", a);

# include "checker.h"

char	*ft_sort_stack(t_stack *a, t_stack *b);
void	ft_qsort_stack_a(t_stack *a, t_stack *b, int size, t_list **head);
void	ft_qsort_stack_b(t_stack *a, t_stack *b, int size, t_list **head);
void	ft_print_stack(t_stack *a, t_stack *b);
void	ft_command_optimization1(t_list **head);
void	ft_command_optimization2(t_list **head);
float	ft_get_median(int *arr, size_t size);
int		ft_check_sort(int *arr, int size);

void	ft_little_sort(t_stack *a, t_stack *b, int size, t_list **head);

#endif
