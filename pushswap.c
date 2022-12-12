/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:02 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/12 13:09:33 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"

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
	quicksort_a(&stack_a, &stack_b, &top, (top.a + 1));
	printall(stack_a, top.a, stack_b, top.b);
	return (0);
}

	// TEST EXERCICE 
	// printall(stack_a, topa + 1, stack_b, topb + 1);
	// swapa(&stack_a, &topa, 0);
	// printall(stack_a, topa + 1, stack_b, topb + 1);
	// pushb(&stack_a, &stack_b, &topa, &topb);
	// pushb(&stack_a, &stack_b, &topa, &topb);
	// pushb(&stack_a, &stack_b, &topa, &topb);
	// printall(stack_a, topa + 1, stack_b, topb + 1);
	// rotabs(&stack_a, &stack_b, &topa, &topb);
	// printall(stack_a, topa + 1, stack_b, topb + 1);
	// revrotabs(&stack_a, &stack_b, &topa, &topb);
	// printall(stack_a, topa + 1, stack_b, topb + 1);
	// swapa(&stack_a, &topa, 0);
	// pusha(&stack_a, &stack_b, &topa, &topb);
	// pusha(&stack_a, &stack_b, &topa, &topb);
	// pusha(&stack_a, &stack_b, &topa, &topb);
	// printall(stack_a, topa + 1, stack_b, topb + 1);
