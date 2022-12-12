/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:42:38 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/13 00:48:10 by kyuuh            ###   ########.fr       */
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

int	ordered(int **stack, int push, char c, t_tops *top)
{
	int	i;

	i = 1;
	//printf("Ordered A check et push %d\n", push);
	if (push <= 1)
		return (1);
	if ((push == 2) && ((*stack)[top->a - 1] < (*stack)[top->a]))
	{
		swap(stack, top->a, 'a');
		return (1);
	}
	while (i < push)
	{
		//printf("a check %d %d\n",(*stack)[top->a-i],(*stack)[top->a-i + 1]);
		if ((*stack)[top->a - i] < (*stack)[top->a - i + 1])
			return (0);
		++i;
	}
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
	while (i < push)
	{
		printf("CHECK DE %d et %d\n",(*stack)[top->b - i],(*stack)[top->b - i + 1]);
		if ((*stack)[top->b - i] > (*stack)[top->b - i + 1])
			return (0);
		++i;
	}
	return (1);
}

void	quicksort_a(int **stack_a, int **stack_b, t_tops *top, int push)
{
	int	push_b;
	int	pivot;
	int	i;
	int itenb;

	i = push;
	itenb = 0;
	push_b = 0;
	printf("quicka : push : %d\n",push);
	printall(*stack_a, top->a, *stack_b, top->b);
	if (ordered(stack_a, push, 'a', top))
		return ;
	pivot = returnpivot(*stack_a, push, top->a);
	while (push)
	{
		if ((*stack_a)[(*top).a] < pivot)
		{
			itenb += pushb(stack_a, stack_b, top);
			++push_b;
		}
		else
			itenb += rot(stack_a, (*top).a, 'a');
		--push;
	}
	backa(stack_a, top->a, itenb, push_b);
	quicksort_a(stack_a, stack_b, top, i - push_b);
	quicksort_b(stack_a, stack_b, top, push_b);
}

void	quicksort_b(int **stack_a, int **stack_b, t_tops *top, int push)
{
	int	pivot;
	int	i;
	int	push_a;
	int	itenb;
	
	i = push;
	itenb = 0;
	push_a = 0;
	printf("quickb : push : %d\n",push);
	printall(*stack_a, top->a, *stack_b, top->b);
	if (orderedb(stack_b, push, 'b', top))
		return (pushback_a(stack_a, stack_b, top, push));
	pivot = returnpivot(*stack_b, push, top->b);
	while (push)
	{
		if ((*stack_b)[(*top).b] > pivot)
		{
			itenb += pusha(stack_a, stack_b, top);
			++push_a;
		}
		else
			itenb += rot(stack_b, (*top).b, 'b');
		--push;
	}
	quicksort_a(stack_a, stack_b, top, push_a);
	quicksort_b(stack_a, stack_b, top, i-push_a);
}
