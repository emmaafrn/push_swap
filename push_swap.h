#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

typedef struct s_chunks
{
	int				divisor;
	int				*chunk_limit;
}				t_chunks;

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
int		ft_atoi(const char *nptr);

t_list	*lst_dup(t_list *lst);
void	pre_sort(t_list **a);

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

void	algo(t_list	**a, t_list **b, t_chunks *chunks_struct);
void	print_lst(t_list	*lst);

void	three_number(t_list	**a);
void	two_number(t_list	**a);
void	tri_three_number(t_list	**a);

void	limits(t_list **a, t_chunks *c_struct);
void	push_values_under_limits(t_list **a, t_list **b, int *limits, t_chunks *c_struct);
void	sort_a(t_list **a, t_list **b);

#endif