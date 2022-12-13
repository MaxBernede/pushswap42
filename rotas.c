/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:38:32 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/13 15:23:25 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "pushswap.h"

int	rota(int **stack, int top, char c)
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
	if (c == 'a')
		write(1, "ra\n", 3);
	return (1);
}

int	rotb(int **stack, int top, char c)
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
	if (c == 'b')
		write(1, "rb\n", 3);
	return (1);
}

void	rotabs(int **stack_a, int **stack_b, int topa, int topb)
{
	rota(stack_a, topa, 'c');
	rotb(stack_b, topb, 'c');
	write(1, "rr\n", 3);
}
