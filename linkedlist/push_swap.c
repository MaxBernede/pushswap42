/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:24:51 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/09 12:40:15 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_pushswap.h"

void	printstack(t_list *alst, t_list *blst)
{
	printf("Stack A :\n");
	ft_lstiter(alst);
	printf("Stack B :\n");
	ft_lstiter(blst);
	printf("\n\n");
}

int main (int argc, char **argv)
{
	t_list *alst;
	t_list *blst;
	int i;
	int anb;
	int bnb;

	i = 2;
	blst = (t_list *)malloc(sizeof(t_list));
	if (argc < 3)
		return 0;
	
	//first arg of linked
	alst = ft_lstnew(argv[1]);
	while (i < argc)
	{
	//adding every node at the end
		ft_lstadd_back(&alst,ft_lstnew(argv[i]));
		++i;
	}
	//print it
	printstack(alst,blst);
	pushb(&alst,&blst);
	printstack(alst,blst);
	return 0;
}
