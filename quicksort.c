/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:42:38 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/12 17:10:36 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"

void	pushback_a(int **stack_a, int **stack_b, t_tops *top, int push)
{
	int	i;

	i = 0;
	while (i < push)
	{
		pusha(stack_a, stack_b, top);
		++i;
	}
}

int	ordered(int **stack, int push, char c)
{
	int	i;

	i = 1;
	if (push <= 1)
	{
		printf("petit stack donc OK\n");
		return (1);
	}
	if ((push == 2) && ((*stack)[i - 1] < (*stack)[i]))
	{
		swap(stack, push - 1, 'a');
		return (1);
	}
	while (i <= push)
	{
		if ((*stack)[i - 1] < (*stack)[i])
		{
			printf("not sorted\n");
			return (0);
		}
		++i;
	}
	printf("SORTED OK A\n");
	return (1);
}

int	orderedb(int **stack, int push, char c, t_tops *top)
{
	int	i;

	i = 1;
	if (push == 1)
		return (1);
	if ((push == 2) && ((*stack)[top->b - 1] > (*stack)[top->b]))
	{
		swap(stack, top->b, 'b');
		return (1);
	}
	while (i <= push)
	{
		if ((*stack)[i - 1] > (*stack)[i])
		{
			printf("not sorted\n");
			return (0);
		}
		++i;
	}
	printf("SORTED OK B et push %d\n", push);
	return (1);
}

void	quicksort_a(int **stack_a, int **stack_b, t_tops *top, int push)
{
	int	push_b;
	int	pivot;
	int	i;

	push_b = 0;
	if (ordered(stack_a, push, 'a'))
		return ;
	pivot = returnpivot(*stack_a, push);
	while (push)
	{
		if ((*stack_a)[(*top).a] < pivot)
		{
			pushb(stack_a, stack_b, top);
			++push_b;
		}
		else
			rot(stack_a, (*top).a, 'a');
		--push;
	}
	quicksort_a(stack_a, stack_b, top, ((*top).a + 1));
	quicksort_b(stack_a, stack_b, top, push_b);
}

void	quicksort_b(int **stack_a, int **stack_b, t_tops *top, int push)
{
	int	pivot;
	int	i;
	int	push_a;
	
	i = push;
	push_a = 0;
	if (orderedb(stack_b, push, 'b', top))
		return (pushback_a(stack_a, stack_b, top, push));
	pivot = returnpivot(*stack_b, push);
	while (push)
	{
		if ((*stack_b)[(*top).b] > pivot)
		{
			pusha(stack_a, stack_b, top);
			++push_a;
		}
		else
			rot(stack_b, (*top).b, 'b');
		--push;
	}
	quicksort_a(stack_a, stack_b, top, push_a);
	quicksort_b(stack_a, stack_b, top, i-push_a);
}
