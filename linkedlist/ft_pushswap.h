/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:19:46 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/06 18:02:43 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

typedef	struct		s_list
{
	int			content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstadd_back(t_list **alst, t_list *new);
t_list	*ft_lstnew(void *content);
void	ft_lstiter(t_list *lst);

void	swap(t_list *lst, char c);
void	ss(t_list *alst, t_list *blst);
void    pushb(t_list **alst, t_list **blst);
void	pusha(t_list **blst, t_list **alst);
void    rotate(t_list **lst);
t_list  *rerotate(t_list **lst);

#endif