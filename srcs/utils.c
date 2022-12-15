/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:06:34 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/15 14:12:35 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../pushswap.h"

void	backb(int **stack, int top, int itenb, int pushn)
{
	while ((itenb - pushn))
	{
		revrotb(stack, top, 'b');
		--itenb;
	}
}

void	backa(int **stack, int top, int itenb, int pushn)
{
	while ((itenb - pushn))
	{
		revrota(stack, top, 'a');
		--itenb;
	}
}

long int	ft_atoilong(char *str)
{
	int			i;
	long int	number;
	long int	neg;

	number = 0;
	i = 0;
	neg = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - 48);
		++i;
	}
	number *= neg;
	return (number);
}

int	checker(int *stack, t_tops *top, char *toadd)
{
	int			i;
	long int	nb;

	i = 0;
	if (toadd[i] == '-')
		++i;
	while (toadd[i])
	{
		if (toadd[i] < 48 || toadd[i] > 57)
			return (0);
		++i;
	}
	i = 0;
	nb = ft_atoilong(toadd);
	if (nb < -2147483648 || nb > 2147483647)
		return (0);
	while (i < (*top).a)
	{
		if (stack[i] == (int)nb)
			return (0);
		++i;
	}
	return (1);
}

int	*stackcrea(int argc, char **argv, t_tops *top, int **stack_a)
{
	if (argc <= 2)
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	while (argc > 1)
	{
		(*top).a += 1;
		--argc;
		if (!checker(*stack_a, top, argv[argc]))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		(*stack_a)[(*top).a] = (int)ft_atoilong(argv[argc]);
	}
	return (*stack_a);
}
