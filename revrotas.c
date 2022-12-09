/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:39:58 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/09 17:40:18 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pushswap.h"

void	revrota(int **stack_a, int *topa, int show)
{
	int	first;
	int	i;

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
	int	first;
	int	i;

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
