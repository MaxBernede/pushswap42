/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:38:32 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/10 18:44:54 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pushswap.h"

void	rot(int **stack, int top, char c)
{
	int	last;
	int	i;

	i = top;
	last = (*stack)[top];
	while (i)
	{
		(*stack)[i] = (*stack)[i - 1];
		--i;
	}
	(*stack)[i] = last;
	if (c == 'a' || c == 'b')
		printf("r%c\n", c);
}

void	rotabs(int **stack_a, int **stack_b, int topa, int topb)
{
	rot(stack_a, topa, 'c');
	rot(stack_b, topb, 'c');
	printf("rr\n");
}

void	revrot(int **stack, int top, char c)
{
	int	first;
	int	i;

	i = 0;
	first = (*stack)[i];
	while (i < top)
	{
		(*stack)[i] = (*stack)[i + 1];
		++i;
	}
	(*stack)[i] = first;
	if (c == 'a' || c == 'b')
		printf("rr%c\n", c);
}

void	revrotabs(int **stack_a, int **stack_b, int topa, int topb)
{
	revrot(stack_a, topa, 'c');
	revrot(stack_b, topb, 'c');
	printf("rrr\n");
}
