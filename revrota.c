/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrota.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:22:53 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/13 15:23:33 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	revrota(int **stack, int top, char c)
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
	if (c == 'a')
		write(1, "rra\n", 4);
}

void	revrotb(int **stack, int top, char c)
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
	if (c == 'b')
		write(1, "rrb\n", 4);
}

void	revrotabs(int **stack_a, int **stack_b, int topa, int topb)
{
	revrota(stack_a, topa, 'c');
	revrotb(stack_b, topb, 'c');
	write(1, "rrr\n", 4);
}
