/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:19:46 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/09 17:40:59 by kyuuh            ###   ########.fr       */
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
void	swapb(int **stack_b, int *topb, int show);
void	swapa(int **stack_a, int *topa, int show);
void	swaps(int **stack_a, int **stack_b, int *topa, int *topb);

void	rotabs(int **stack_a, int **stack_b, int *topa, int *topb);
void	rotb(int **stack_b, int *topb, int show);
void	rota(int **stack_a, int *topa, int show);

void	revrotabs(int **stack_a, int **stack_b, int *topa, int *topb);
void	revrotb(int **stack_b, int *topb, int show);
void	revrota(int **stack_a, int *topa, int show);

#endif