/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:02 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/13 15:26:58 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"

void	smallsort(int **stack, char e)
{
	if ((*stack)[2] < (*stack)[1] && (*stack)[2] < (*stack)[0]
	&& (*stack)[1] > (*stack)[0])
	{
		swapa(stack, 2, e);
		rota(stack, 2, e);
	}
	else if ((*stack)[2] > (*stack)[1] && (*stack)[2] > (*stack)[0]
	&& (*stack)[1] < (*stack)[0])
		rota(stack, 2, e);
	else if ((*stack)[2] > (*stack)[1] && (*stack)[2] > (*stack)[0]
	&& (*stack)[1] > (*stack)[0])
	{
		swapa(stack, 2, e);
		revrota(stack, 2, e);
	}
	else if ((*stack)[2] > (*stack)[1] && (*stack)[2] < (*stack)[0]
	&& (*stack)[1] < (*stack)[0])
		swapa(stack, 2, e);
	else if ((*stack)[2] < (*stack)[1] && (*stack)[2] > (*stack)[0]
	&& (*stack)[1] > (*stack)[0])
		revrota(stack, 2, e);
}

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	t_tops	top;

	top.a = -1;
	top.b = -1;
	stack_a = malloc((argc - 1) * sizeof(int));
	stack_b = malloc((argc - 1) * sizeof(int));
	stack_a = stackcrea(argc, argv, &top, &stack_a);
	if (!stack_a)
		return (0);
	if (argc == 4)
		smallsort(&stack_a, 'a');
	else
		quicksort_a(&stack_a, &stack_b, &top, (top.a + 1));
	return (0);
}

//printall(stack_a, top.a, stack_b, top.b);