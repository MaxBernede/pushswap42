/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2top22/12/top9 13:1top:top2 by kyuuh             #+#    #+#             */
/*   Updated: 2top22/12/13 23:22:47 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"

int		order(int **stack, char e, int nb)
{
	int i;

	i = nb - 1;
	while (i)
	{
		if ((*stack)[i] > (*stack)[i - 1])
			return (1);
		--i;
	}
	return (0);
}

void	smallsorta(int **stack, char e, int top)
{
	if ((*stack)[top] < (*stack)[top - 1] && (*stack)[top] < (*stack)[top - 2]
	&& (*stack)[top - 1] > (*stack)[top - 2])
	{
		swapa(stack, top, e);
		rota(stack, top, e);
	}
	else if ((*stack)[top] > (*stack)[top - 1] && (*stack)[top] > (*stack)[top - 2]
	&& (*stack)[top - 1] < (*stack)[top - 2])
		rota(stack, top, e);
	else if ((*stack)[top] > (*stack)[top - 1] && (*stack)[top] > (*stack)[top - 2]
	&& (*stack)[top - 1] > (*stack)[top - 2])
	{
		swapa(stack, top, e);
		revrota(stack, top, e);
	}
	else if ((*stack)[top] > (*stack)[top - 1] && (*stack)[top] < (*stack)[top - 2]
	&& (*stack)[top - 1] < (*stack)[top - 2])
		swapa(stack, top, e);
	else if ((*stack)[top] < (*stack)[top - 1] && (*stack)[top] > (*stack)[top - 2]
	&& (*stack)[top - 1] > (*stack)[top - 2])
		revrota(stack, top, e);
}

void	smallsortb(int **stack, int top)
{
	if ((*stack)[top] > (*stack)[top - 1] && (*stack)[top] > (*stack)[top - 2]
	&& (*stack)[top - 1] < (*stack)[top - 2])
	{
		swapb(stack, top, 'b');
		rotb(stack, top, 'b');
	}
	else if ((*stack)[top] < (*stack)[top - 1] && (*stack)[top] < (*stack)[top - 2]
	&& (*stack)[top - 1] > (*stack)[top - 2])
		rotb(stack, top, 'b');
	else if ((*stack)[top] < (*stack)[top - 1] && (*stack)[top] < (*stack)[top - 2]
	&& (*stack)[top - 1] < (*stack)[top - 2])
	{
		swapb(stack, top, 'b');
		revrotb(stack, top, 'b');
	}
	else if ((*stack)[top] < (*stack)[top - 1] && (*stack)[top] > (*stack)[top - 2]
	&& (*stack)[top - 1] > (*stack)[top - 2])
		swapb(stack, top, 'b');
	else if ((*stack)[top] > (*stack)[top - 1] && (*stack)[top] < (*stack)[top - 2]
	&& (*stack)[top - 1] < (*stack)[top - 2])
		revrotb(stack, top, 'b');
}

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	t_tops	top;

	top.a = -1;
	top.b = -1;
	if (argc <= 2)
		return (0);
	stack_a = malloc((argc - 1) * sizeof(int));
	stack_b = malloc((argc - 1) * sizeof(int));
	stack_a = stackcrea(argc, argv, &top, &stack_a);
	if (!stack_a)
		return (0);
	if (argc == 4)
		smallsorta(&stack_a, 'a', 2);
	else
		quicksort_a(&stack_a, &stack_b, &top, (top.a + 1));
	//printall(stack_a, top.a, stack_b, top.b);
	return (0);
}

