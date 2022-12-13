/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:06:34 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/13 01:11:05 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"

void	backa(int **stack, int top, int itenb, int pushn)
{
	while (itenb <= (top + pushn))
		{
			rot(stack, top, 'a');
			++itenb;
		}
}

void	printall(int *stack_a, int topa, int *stack_b, int topb)
{
	int	i;

	if (topa > topb)
		i = topa;
	else
		i = topb;
	while (i >= 0)
	{
		if (i <= topa)
			printf("%d  ", stack_a[i]);
		else
			printf("   ");
		if (i <= topb)
			printf("%d", stack_b[i]);
		printf("\n");
		--i;
	}
	printf(" A  B\n");
}

int	checker(int *stack, t_tops *top, char *toadd)
{
	int	i;
	int	nb;

	i = 0;
	if (toadd[i] == '-')
		++i;
	while (toadd[i])
	{
		if (toadd[i] < 48 || toadd[i] > 57)
			return (0);
		++i;
	}
	i = 0;
	nb = atoi(toadd);
	while (i < (*top).a)
	{
		if (stack[i] == nb)
			return (0);
		++i;
	}
	return (1);
}

int	*stackcrea(int argc, char **argv, t_tops *top, int **stack_a)
{
	if (argc <= 2)
	{
		printf("Error : Not enough args\n");
		return (NULL);
	}
	while (argc > 1)
	{
		(*top).a += 1;
		--argc;
		if (!checker(*stack_a, top, argv[argc]))
		{
			printf("Error : duplicated arg\n");
			return (0);
		}
		(*stack_a)[(*top).a] = atoi(argv[argc]);
	}
	return (*stack_a);
}
