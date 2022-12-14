/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:35:38 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/14 13:37:38 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../pushswap.h"

int	pusha(int **stack_a, int **stack_b, t_tops *top)
{
	if ((*top).b < 0)
		return (0);
	(*top).a += 1;
	(*stack_a)[(*top).a] = (*stack_b)[(*top).b];
	(*top).b -= 1;
	write(1, "pa\n", 3);
	return (1);
}

int	pushb(int **stack_a, int **stack_b, t_tops *top)
{
	if ((*top).a < 0)
		return (0);
	(*top).b += 1;
	(*stack_b)[(*top).b] = (*stack_a)[(*top).a];
	(*top).a -= 1;
	write(1, "pb\n", 3);
	return (1);
}

void	swapa(int **stack, int top, char c)
{
	int	temp;

	if (top <= 0)
		return ;
	temp = (*stack)[top];
	(*stack)[top] = (*stack)[top - 1];
	(*stack)[top - 1] = temp;
	if (c == 'a')
		write(1, "sa\n", 3);
}

void	swapb(int **stack, int top, char c)
{
	int	temp;

	if (top <= 0)
		return ;
	temp = (*stack)[top];
	(*stack)[top] = (*stack)[top - 1];
	(*stack)[top - 1] = temp;
	if (c == 'b')
		write(1, "sb\n", 3);
}

void	swaps(int **stack_a, int **stack_b, int topa, int topb)
{
	swapa(stack_a, topa, 'c');
	swapb(stack_b, topb, 'c');
	write(1, "ss\n", 3);
}
