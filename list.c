/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 09:15:51 by efarin            #+#    #+#             */
/*   Updated: 2021/05/13 09:16:11 by efarin           ###   ########lyon.fr   */
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
	t_list	*temp;

	temp = NULL;
	if (alst == NULL)
		alst = &new;
	else
	{
		temp = ft_lstlast(*alst);
		temp->next = new;
	}
}

// void	ft_lstadd_back(t_list **alst, t_list *new)
// {
// 	t_list	*ok;

// 	if (*alst == NULL)
// 	{
// 		*alst = new;
// 		return ;
// 	}
// 	ok = *alst;
// 	while (ok->next != NULL)
// 		ok = ok->next;
// 	ok->next = new;
// }

// void	ft_lstclear(t_list **lst, void (*del)(void*))
// {
// 	t_list	*ok;

// 	ok = (*lst);
// 	while (ok != NULL)
// 	{
// 		ok = (*lst)->next;
// 		del((*lst)->content);
// 		free((*lst));
// 		(*lst) = ok;
// 	}
// 	(*lst) = NULL;
// }

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