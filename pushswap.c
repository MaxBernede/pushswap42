/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:02 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/13 13:38:46 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"

// void	smallsort(int **stack, char e)
// {
// 	int a;
// 	int b;
// 	int c;

// 	a = (*stack)[2];
// 	b = (*stack)[1];
// 	c = (*stack)[0];
// 	printf("a b c %d %d %d\n",a ,b ,c);
// 	if (a > b)
// 		swap(stack, 2, e);
// 	//revrot(stack, 2, e);
// 	if (b > z)
// 	{
// 		swap(stack, 2, e);
// 		rot(stack, 2, e);
// 	}
// 	else if (a > b)
// 		rot(stack, 2, e);
// }

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	t_tops	top;

	top.a = -1;
	top.b = -1;
	stack_a = malloc((argc - 1) * sizeof(int));
	stack_b = malloc((argc - 1) * sizeof(int));
	stack_a = stackcrea(argc, argv, &top, &stack_a);
	if (!stack_a)
		return (0);
	// if (argc == 4)
	// 	smallsort(&stack_a, 'a');
	quicksort_a(&stack_a, &stack_b, &top, (top.a + 1));
	printall(stack_a, top.a, stack_b, top.b);
	return (0);
}
