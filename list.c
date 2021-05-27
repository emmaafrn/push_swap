/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <bmoulin@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 09:15:51 by efarin            #+#    #+#             */
/*   Updated: 2021/05/14 11:14:41 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*liste;

	liste = malloc(sizeof(t_list));
	if (!(liste))
		return (NULL);
	liste->content = content;
	liste->next = NULL;
	return (liste);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list		*tmp;

	if (*alst == NULL)
		*alst = new;
	else
	{
		tmp = ft_lstlast(*alst);
		tmp->next = new;
		tmp->next->next = NULL;
	}
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (new == NULL)
		return ;
	new = ft_lstlast(new);
	new->next = *alst;
	new = new->next;
	*alst = new;
}


int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*ok;

	ok = (*lst);
	while (ok != NULL)
	{
		ok = (*lst)->next;
		free((*lst));
		(*lst) = ok;
	}
	(*lst) = NULL;
}
