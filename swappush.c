/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:35:38 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/13 00:42:54 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pushswap.h"

int	pusha(int **stack_a, int **stack_b, t_tops *top)
{
	if ((*top).b < 0)
	{
		printf("stack B empty, no push\n");
		return (0);
	}
	(*top).a += 1;
	(*stack_a)[(*top).a] = (*stack_b)[(*top).b];
	(*top).b -= 1;
	printf("pa\n");
	return (1);
}

int	pushb(int **stack_a, int **stack_b, t_tops *top)
{
	if ((*top).a < 0)
	{
		printf("stack A empty, no push\n");
		return (0);
	}
	(*top).b += 1;
	(*stack_b)[(*top).b] = (*stack_a)[(*top).a];
	(*top).a -= 1;
	printf("pb\n");
	return (1);
}

void	swap(int **stack, int top, char c)
{
	int	temp;

	if (top <= 0)
	{
		printf("not enough in stack b for swap\n");
		return ;
	}
	temp = (*stack)[top];
	(*stack)[top] = (*stack)[top - 1];
	(*stack)[top - 1] = temp;
	if (c == 'b' || c == 'a')
		printf("s%c\n", c);
}

void	swaps(int **stack_a, int **stack_b, int topa, int topb)
{
	swap(stack_a, topa, 'c');
	swap(stack_b, topb, 'c');
	printf("ss\n");
}
