/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivottemp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:22:46 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/11 18:44:46 by kyuuh            ###   ########.fr       */
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

int	returnpivot(int *stack, int top)
{
	int	*temp;
	int	pivot;
	int	i;

	i = -1;
	temp = malloc((top) * sizeof(int));
	if (!temp)
		return (0);
	while (++i <= top)
		temp[i] = stack[i];
	sort(&temp, top);
	pivot = temp[(top / 2)];
	free(temp);
	printf("pivot mon couillon %d\n", pivot);
	return (pivot);
}
