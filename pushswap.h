
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:19:46 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/13 01:17:08 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef	struct top
{
	int a;
	int b;
}	t_tops;

void	printstack(int *stack, int top);
void	printall(int *stack_a, int topa, int *stack_b, int topb);
int		checker(int *stack, t_tops *top, char *toadd);
int		*stackcrea(int argc, char **argv, t_tops *top, int **stack_a);

int		pusha(int **stack_a, int **stack_b, t_tops *top);
int		pushb(int **stack_a, int **stack_b, t_tops *top);
void	swap(int **stack, int top, char c);
void	swaps(int **stack_a, int **stack_b, int topa, int topb);

void	rotabs(int **stack_a, int **stack_b, int topa, int topb);
int		rot(int **stack, int top, char c);
void	revrotabs(int **stack_a, int **stack_b, int topa, int topb);
void	revrot(int **stack, int top, char c);

int		returnpivot(int *stack, int push, int top);
void	backa(int **stack, int top, int itenb, int pushn);
void	backb(int **stack, int top, int itenb, int pushn);

void	quicksort_a(int **stack_a, int **stack_b, t_tops *top, int push);
void	quicksort_b(int **stack_a, int **stack_b, t_tops *top, int push);

#endif