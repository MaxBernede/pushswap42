/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:02 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/09 17:08:05 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"

//call printstack with len a and +1 because the way index are calculated

void	revrota(int **stack_a, int *topa, int show)
{
	int first;
	int i;

	i = 0;
	first = (*stack_a)[i];
	while (i < *topa)
	{
		(*stack_a)[i] = (*stack_a)[i + 1];
		++i;
	}
	(*stack_a)[i] = first;
	if (!show)
		printf("rra\n");
}

void	revrotb(int **stack_b, int *topb, int show)
{
	int first;
	int i;

	i = 0;
	first = (*stack_b)[i];
	while (i < *topb)
	{
		(*stack_b)[i] = (*stack_b)[i + 1];
		++i;
	}
	(*stack_b)[i] = first;
	if (!show)
		printf("rrb\n");
}

void	revrotabs(int **stack_a, int **stack_b, int *topa, int *topb)
{
	revrota(stack_a, topa, 1);
	revrotb(stack_b, topb, 1);
	printf("rrr\n");
}

void	rota(int **stack_a, int *topa, int show)
{
	int last;
	int i;

	i = *topa;
	last = (*stack_a)[*topa];
	while (i)
	{
		(*stack_a)[i] = (*stack_a)[i - 1];
		--i;
	}
	(*stack_a)[i] = last;
	if (!show)
		printf("ra\n");
}

void	rotb(int **stack_b, int *topb, int show)
{
	int last;
	int i;

	i = *topb;
	last = (*stack_b)[*topb];
	while (i)
	{
		(*stack_b)[i] = (*stack_b)[i - 1];
		--i;
	}
	(*stack_b)[i] = last;
	if (!show)
		printf("rb\n");
}

void	rotabs(int **stack_a, int **stack_b, int *topa, int *topb)
{
	rota(stack_a, topa, 1);
	rotb(stack_b, topb, 1);
	printf("rr\n");
}

void	pusha(int **stack_a, int **stack_b, int *topa, int *topb)
{
	if (*topb < 0)
	{
		printf("stack B empty, no push\n");
		return ;
	}
	*topa += 1;
	(*stack_a)[*topa] = (*stack_b)[*topb];
	*topb -= 1;
	printf("pa\n");
}

void	pushb(int **stack_a, int **stack_b, int *topa, int *topb)
{
	if (*topa < 0)
	{
		printf("stack A empty, no push\n");
		return ;
	}
	*topb += 1;
	(*stack_b)[*topb] = (*stack_a)[*topa];
	*topa -= 1;
	printf("pb\n");
}

void	swapb(int **stack_b, int *topb, int show)
{
	int	temp;

	if (*topb <= 0)
	{
		printf("not enough in stack b for swap\n");
		return ;
	}
	temp = (*stack_b)[*topb];
	(*stack_b)[*topb] = (*stack_b)[*topb - 1];
	(*stack_b)[*topb - 1] = temp;
	if (!show)
		printf("sb\n");
}

void	swapa(int **stack_a, int *topa, int show)
{
	int	temp;

	if (*topa <= 0)
	{
		printf("not enough in stack a for swap\n");
		return ;
	}
	temp = (*stack_a)[*topa];
	(*stack_a)[*topa] = (*stack_a)[*topa - 1];
	(*stack_a)[*topa - 1] = temp;
	if (!show)
		printf("sa\n");
}

void	swaps(int **stack_a, int **stack_b, int *topa, int *topb)
{
	swapa(stack_a, topa, 1);
	swapb(stack_b, topb, 1);
	printf("ss\n");
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	topb;
	int	topa;

	topa = -1;
	topb = -1;
	stack_a = malloc((argc - 1) * sizeof(int));
	stack_b = malloc((argc - 1) * sizeof(int));
	
	stack_a = stackcrea(argc, argv, &topa, &stack_a);
	if (!stack_a)
		return (0);

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
	return (0);
}
