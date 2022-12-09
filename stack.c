/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:06:34 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/09 18:05:47 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"

void	printstack(int *stack, int top)
{
	if (top <= 0)
	{
		printf("* * * Stack empty * * *\n");
		return ;
	}
	while (top > 0)
	{
		--top;
		printf("%d\n", stack[top]);
	}
}

void	printall(int *stack_a, int topa, int *stack_b, int topb)
{
	printf("Stack A : \n");
	printstack(stack_a, topa);
	printf("Stack b : \n");
	printstack(stack_b, topb);
}

int	checker(int *stack, int top, char *toadd)
{
	int	i;
	int	nb;

	i = 0;
	while (toadd[i])
	{
		if (toadd[i] < 48 || toadd[i] > 57)
			return (0);
		++i;
	}
	i = 0;
	nb = atoi(toadd);
	while (i < top)
	{
		if (stack[i] == nb)
			return (0);
		++i;
	}
	return (1);
}

int	*stackcrea(int argc, char **argv, int *topa, int **stack_a)
{
	if (argc <= 2)
	{
		printf("Error : Not enough args\n");
		return (NULL);
	}
	while (argc > 1)
	{
		*topa += 1;
		--argc;
		if (!checker(*stack_a, *topa, argv[argc]))
		{
			printf("Error : dupplicated arg\n");
			return (0);
		}
		(*stack_a)[*topa] = atoi(argv[argc]);
	}
	return (*stack_a);
}
