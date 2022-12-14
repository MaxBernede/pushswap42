/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:19:46 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/14 14:01:52 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct top
{
	int	a;
	int	b;
}	t_tops;

void	printstack(int *stack, int top);
void	printall(int *stack_a, int topa, int *stack_b, int topb);
int		checker(int *stack, t_tops *top, char *toadd);
int		*stackcrea(int argc, char **argv, t_tops *top, int **stack_a);

int		pusha(int **stack_a, int **stack_b, t_tops *top);
int		pushb(int **stack_a, int **stack_b, t_tops *top);
void	swapa(int **stack, int top, char c);
void	swapb(int **stack, int top, char c);
void	swaps(int **stack_a, int **stack_b, int topa, int topb);

void	rotabs(int **stack_a, int **stack_b, int topa, int topb);
int		rota(int **stack, int top, char c);
int		rotb(int **stack, int top, char c);
void	revrota(int **stack, int top, char c);
void	revrotb(int **stack, int top, char c);
void	revrotabs(int **stack_a, int **stack_b, int topa, int topb);

int		returnpivot(int *stack, int push, int top);
void	backa(int **stack, int top, int itenb, int pushn);
void	backb(int **stack, int top, int itenb, int pushn);

void	quicksort_a(int **stack_a, int **stack_b, t_tops *top, int push);
void	quicksort_b(int **stack_a, int **stack_b, t_tops *top, int push);
void	smallsorta(int **stack, char e, int top);
void	smallsortb(int **stack, int top);

void	smola(int **stack, char e, int top);
void	endsmola(int **stack, char e, int top);
void	smolb(int **stack, char e, int top);
void	endsmolb(int **stack, char e, int top);
void	issmola(int **stack, char e, int top, int push);
void	issmolb(int **stack, char e, int top, int push);

#endif