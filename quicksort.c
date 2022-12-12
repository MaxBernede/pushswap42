/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:42:38 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/12 01:20:13 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"

int	ordered(int **stack, int top, char c)
{
	int	i;

	i = 1;
	if (top <= 1)
	{
		printf("petit stack donc OK\n");
		return (1);
	}
	if ((top == 2) && ((*stack)[i - 1] < (*stack)[i]))
	{
		swap(stack, top - 1, 'a');
		return (1);
	}
	while (i <= top)
	{
		if ((*stack)[i - 1] < (*stack)[i])
		{
			printf("not sorted\n");
			return (0);
		}
		++i;
	}
	printf("SORTED OK\n");
	return (1);
}

int	orderedb(int **stack, int top, char c)
{
	int	i;

	i = 1;
	if (top <= 1)
	{
		printf("petit stack donc OK\n");
		return (1);
	}
	if ((top == 2) && ((*stack)[i - 1] < (*stack)[i]))
	{
		swap(stack, top - 1, 'b');
		return (1);
	}
	while (i <= top)
	{
		if ((*stack)[i - 1] > (*stack)[i])
		{
			printf("not sorted\n");
			return (0);
		}
		++i;
	}
	printf("SORTED OK\n");
	return (1);
}

void	quicksort_a(int **stack_a, int *topa, int **stack_b, int *topb)
{
	int	rest;
	int	pivot;
	int	push;
	int	i;

	rest = *topa + 1;
	push = 0;
	printf("ONE QUICK\n");
	if (ordered(stack_a, rest, 'a'))
		return ;
	pivot = returnpivot(*stack_a, rest);
	while (rest)
	{
		if ((*stack_a)[*topa] < pivot)
		{
			pushb(stack_a, stack_b, topa, topb);
			++push;
		}
		else
			rot(stack_a, *topa, 'a');
		printall(*stack_a, *topa, *stack_b, *topb);
		--rest;
	}
	quicksort_a(stack_a, topa, stack_b, topb);
	//quicksort_b(stack_a, topa, stack_b, topb);
}

void	quicksort_b(int **stack_a, int *topa, int **stack_b, int *topb)
{
	int	rest;
	int	pivot;
	int	push;
	int	i;

	rest = *topa + 1;
	push = 0;
	printf("QUICKSORT B\n");
	if (orderedb(stack_a, rest, 'a'))
		return ;
	pivot = returnpivot(*stack_a, rest);
	while (rest)
	{
		if ((*stack_a)[*topa] < pivot)
		{
			pushb(stack_a, stack_b, topa, topb);
			++push;
		}
		else
			rot(stack_a, *topa, 'a');
		printall(*stack_a, *topa, *stack_b, *topb);
		--rest;
	}
	quicksort_a(stack_a, topa, stack_b, topb);
	quicksort_b(stack_a, topa, stack_b, topb);
}