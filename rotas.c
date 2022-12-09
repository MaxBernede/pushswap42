/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:38:32 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/09 17:39:43 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pushswap.h"

void	rota(int **stack_a, int *topa, int show)
{
	int	last;
	int	i;

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
	int	last;
	int	i;

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