/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:19:46 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/11 18:44:54 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

void	printstack(int *stack, int top);
void	printall(int *stack_a, int topa, int *stack_b, int topb);
int		checker(int *stack, int top, char *toadd);
int		*stackcrea(int argc, char **argv, int *topa, int **stack_a);

void	pusha(int **stack_a, int **stack_b, int *topa, int *topb);
void	pushb(int **stack_a, int **stack_b, int *topa, int *topb);
void	swap(int **stack, int top, char c);
void	swaps(int **stack_a, int **stack_b, int topa, int topb);

void	rotabs(int **stack_a, int **stack_b, int topa, int topb);
void	rot(int **stack, int top, char c);
void	revrotabs(int **stack_a, int **stack_b, int topa, int topb);
void	revrot(int **stack, int top, char c);

int		returnpivot(int *stack, int top);

int		ordered(int **stack, int top, char c);

void	quicksort_a(int **stack_a, int *topa, int **stack_b, int *topb);

#endif