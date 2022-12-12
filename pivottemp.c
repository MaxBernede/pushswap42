/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivottemp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:22:46 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/12 18:20:32 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// void printArray(int arr[], int n)
// {
//     int i;
//     for (i = 0; i < n; i++)
//         printf("%d ", arr[i]);
//     printf("\n");
// }

void	sort(int **arr, int n)
{
	int	i;
	int	key;
	int	j;

	i = 1;
	while (i < n)
	{
		key = (*arr)[i];
		j = i - 1;
		while (j >= 0 && (*arr)[j] < key)
		{
			(*arr)[j + 1] = (*arr)[j];
			j = j - 1;
		}
		(*arr)[j + 1] = key;
		++i;
	}
}

int	returnpivot(int *stack, int push, int top)
{
	int	*temp;
	int	pivot;
	int	i;

	i = -1;
	temp = malloc((push) * sizeof(int));
	if (!temp)
		return (0);
	while (++i < push)
		temp[i] = stack[top - push + i + 1];
	sort(&temp, push);
	pivot = temp[(push / 2)];
	free(temp);
	printf("pivot mon couillon %d\n", pivot);
	return (pivot);
}
