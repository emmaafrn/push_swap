#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;


t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
int		ft_atoi(const char *nptr);

void	swap_b(t_list *b);
void	swap_a(t_list *a);
void	swap_ab(t_list *a, t_list *b);

void	rev_rotate_a(t_list **a);
void	rev_rotate_b(t_list **b);
void	rev_rotate_a_and_b(t_list **a, t_list **b);

void	rotate_b(t_list	**a);
void	rotate_a(t_list	**a);
void	rotate_ab(t_list **a, t_list **b);

void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);

void	algo(t_list	**a, t_list	**b);
void	print_lst(t_list	*lst);

#endif