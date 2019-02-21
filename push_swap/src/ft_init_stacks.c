/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:06:04 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/27 21:00:48 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char		ft_read_flags(char *str, char *flags)
{
	int		flg;

	flg = 0;
	if (*str == '-')
	{
		str++;
		while (*str)
		{
			if (*str == 'v')
				flg |= DEBUG_FLAG;
			else if (*str == 'c')
				flg |= COLOR_FLAG;
			else if (flg != 0)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			else
				return (0);
			str++;
		}
		*flags |= flg;
		return (1);
	}
	return (0);
}

static void		ft_check_arg(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		str++;
	}
}

static void		ft_check_unique(int n, int *arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (n == arr[i])
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

static t_stack	*ft_init_stack(size_t size, char **argv, char flags)
{
	size_t	i;
	long	tmp;
	t_stack	*stack;

	stack = ft_stk_create(size, flags);
	tmp = 0;
	i = 0;
	while (i < size)
	{
		ft_check_arg(argv[size - 1 - i]);
		tmp = ft_atoi(argv[size - 1 - i]);
		if (tmp > 2147483647 || tmp < -2147483648)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		stack->data[i] = (int)tmp;
		ft_check_unique(stack->data[i], stack->data, i);
		stack->top++;
		i++;
	}
	return (stack);
}

int				ft_init_stacks(t_stack **a, t_stack **b, int ac, char **av)
{
	size_t	size;
	char	**args;
	char	flags;

	flags = 0;
	size = 1;
	args = NULL;
	while ((int)size < ac && (ft_read_flags(av[size], &flags)))
		size++;
	if (ac - size == 1)
	{
		if (!(args = ft_strsplit(av[size], ' ')))
			exit(OUT_OF_MEMORY);
		size = 0;
		while (args[size])
			size++;
	}
	else
	{
		args = av + size;
		size = ac - size;
	}
	*a = ft_init_stack(size, args, flags);
	*b = ft_stk_create(size, flags);
	return (*a ? 1 : 0);
}
