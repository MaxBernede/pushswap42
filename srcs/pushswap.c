/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0002/12/09 13:01:00 by top2 by kyu       #+#    #+#             */
/*   Updated: 2022/12/15 14:14:54 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../pushswap.h"

void	smallsorta(int **stack, char e, int top)
{
	if ((*stack)[top] < (*stack)[top - 1] && (*stack)[top] <
	(*stack)[top - 2] && (*stack)[top - 1] > (*stack)[top - 2])
	{
		swapa(stack, top, e);
		rota(stack, top, e);
	}
	else if ((*stack)[top] > (*stack)[top - 1] && (*stack)[top] >
	(*stack)[top - 2] && (*stack)[top - 1] < (*stack)[top - 2])
		rota(stack, top, e);
	else if ((*stack)[top] > (*stack)[top - 1] && (*stack)[top] >
	(*stack)[top - 2] && (*stack)[top - 1] > (*stack)[top - 2])
	{
		swapa(stack, top, e);
		revrota(stack, top, e);
	}
	else if ((*stack)[top] > (*stack)[top - 1] && (*stack)[top] <
	(*stack)[top - 2] && (*stack)[top - 1] < (*stack)[top - 2])
		swapa(stack, top, e);
	else if ((*stack)[top] < (*stack)[top - 1] && (*stack)[top] >
	(*stack)[top - 2] && (*stack)[top - 1] > (*stack)[top - 2])
		revrota(stack, top, e);
}

void	smallsortb(int **stack, int top)
{
	if ((*stack)[top] > (*stack)[top - 1] && (*stack)[top] >
	(*stack)[top - 2] && (*stack)[top - 1] < (*stack)[top - 2])
	{
		swapb(stack, top, 'b');
		rotb(stack, top, 'b');
	}
	else if ((*stack)[top] < (*stack)[top - 1] && (*stack)[top] <
	(*stack)[top - 2] && (*stack)[top - 1] > (*stack)[top - 2])
		rotb(stack, top, 'b');
	else if ((*stack)[top] < (*stack)[top - 1] && (*stack)[top] <
	(*stack)[top - 2] && (*stack)[top - 1] < (*stack)[top - 2])
	{
		swapb(stack, top, 'b');
		revrotb(stack, top, 'b');
	}
	else if ((*stack)[top] < (*stack)[top - 1] && (*stack)[top] >
	(*stack)[top - 2] && (*stack)[top - 1] > (*stack)[top - 2])
		swapb(stack, top, 'b');
	else if ((*stack)[top] > (*stack)[top - 1] && (*stack)[top] <
	(*stack)[top - 2] && (*stack)[top - 1] < (*stack)[top - 2])
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
	return (0);
}
