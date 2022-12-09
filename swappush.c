/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:35:38 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/09 17:38:02 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pushswap.h"

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
