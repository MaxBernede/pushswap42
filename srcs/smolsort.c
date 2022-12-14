/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smolsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:04:00 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/14 13:38:04 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	smola(int **stack, char e, int top)
{
	if ((*stack)[top] > (*stack)[top - 1] && (*stack)[top] >
	(*stack)[top - 2] && (*stack)[top - 1] < (*stack)[top - 2])
	{
		swapa(stack, top, e);
		rota(stack, top, e);
		swapa(stack, top, e);
		revrota(stack, top, e);
	}
	else if ((*stack)[top] > (*stack)[top - 1] && (*stack)[top] >
	(*stack)[top - 2] && (*stack)[top - 1] > (*stack)[top - 2])
	{
		swapa(stack, top, e);
		rota(stack, top, e);
		swapa(stack, top, e);
		revrota(stack, top, e);
		swapa(stack, top, e);
	}
	else
		endsmola(stack, e, top);
}

void	endsmola(int **stack, char e, int top)
{
	if ((*stack)[top] < (*stack)[top - 1] && (*stack)[top] <
	(*stack)[top - 2] && (*stack)[top - 1] > (*stack)[top - 2])
	{
		rota(stack, top, e);
		swapa(stack, top, e);
		revrota(stack, top, e);
	}
	else if ((*stack)[top] > (*stack)[top - 1] && (*stack)[top] <
	(*stack)[top - 2] && (*stack)[top - 1] < (*stack)[top - 2])
		swapa(stack, top, e);
	else if ((*stack)[top] < (*stack)[top - 1] && (*stack)[top] >
	(*stack)[top - 2] && (*stack)[top - 1] > (*stack)[top - 2])
	{
		rota(stack, top, e);
		swapa(stack, top, e);
		revrota(stack, top, e);
		swapa(stack, top, e);
	}
}

void	smolb(int **stack, char e, int top)
{
	if ((*stack)[top] < (*stack)[top - 1] && (*stack)[top] <
	(*stack)[top - 2] && (*stack)[top - 1] > (*stack)[top - 2])
	{
		swapb(stack, top, e);
		rotb(stack, top, e);
		swapb(stack, top, e);
		revrotb(stack, top, e);
	}
	else if ((*stack)[top] < (*stack)[top - 1] && (*stack)[top] <
	(*stack)[top - 2] && (*stack)[top - 1] < (*stack)[top - 2])
	{
		swapb(stack, top, e);
		rotb(stack, top, e);
		swapb(stack, top, e);
		revrotb(stack, top, e);
		swapb(stack, top, e);
	}
	else
		endsmolb(stack, e, top);
}

void	endsmolb(int **stack, char e, int top)
{
	if ((*stack)[top] > (*stack)[top - 1] && (*stack)[top] >
	(*stack)[top - 2] && (*stack)[top - 1] < (*stack)[top - 2])
	{
		rotb(stack, top, e);
		swapb(stack, top, e);
		revrotb(stack, top, e);
	}
	else if ((*stack)[top] < (*stack)[top - 1] && (*stack)[top] >
	(*stack)[top - 2] && (*stack)[top - 1] > (*stack)[top - 2])
		swapb(stack, top, e);
	else if ((*stack)[top] > (*stack)[top - 1] && (*stack)[top] <
	(*stack)[top - 2] && (*stack)[top - 1] < (*stack)[top - 2])
	{
		rotb(stack, top, e);
		swapb(stack, top, e);
		revrotb(stack, top, e);
		swapb(stack, top, e);
	}
}
