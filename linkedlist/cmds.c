/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:23:17 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/09 12:48:39 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_pushswap.h"

void ss(t_list *alst, t_list *blst)
{
	swap(alst, 'z');
	swap(blst, 'z');
	printf("ss\n");
}

void swap(t_list *lst, char c)
{
    int temp;
    t_list  *after;

	if (lst->next == NULL || !lst)
		return;
    after = lst->next;
    temp = lst->content;
    lst->content = after->content;
    after->content = temp;
	if (c == 'a' || c == 'b')
		printf("s%c\n",c);
}

//IL Y AURA UN PB SI PREMIERE VALEUR EST 0
void pushb(t_list **alst, t_list **blst)
{
	t_list *temp;
	t_list	*nexty;

	if (!*alst)
		return;
	temp = *alst;
	nexty = temp->next;
	if (!(*blst)->content && !(*blst)->next)
		(*blst)->content = temp->content;
	else
		ft_lstadd_front(blst,temp);
	if (nexty->next == NULL)
		*alst = nexty;
	printf("pb\n");
}

void pusha(t_list **blst, t_list **alst)
{
	t_list *temp;
	t_list	*nexty;

	if (!*alst)
		return;
	temp = *alst;
	nexty = (*alst)->next;
	if (!(*blst)->content && (*blst)->next == NULL)
		(*blst)->content = temp->content;
	else
		ft_lstadd_front(blst,temp);
	*alst = nexty;
	printf("pa\n");
}

void rotate(t_list **lst)
{
	t_list *temp;
	t_list *last;

	temp = *lst;
	last = ft_lstlast(*lst);
	last->next = temp;
	*lst = temp->next;
	temp->next = NULL;
}

t_list *rerotate(t_list **lst)
{
	t_list *last;
	t_list *previous;

	previous = *lst;
	last = (*lst)->next;
	while (previous)
	{
		if (last->next == NULL)
			break;
		previous = last;	
		last = last->next;
	}
	last->next = *lst;
	previous->next = NULL;
	return (last);
}
