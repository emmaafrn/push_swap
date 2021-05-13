#include "../push_swap.h"

void	push_a(t_list **a, t_list **b)
{
	t_list	*first;

	if (!*b)
		return ;
	first = *b;
	ft_lstadd_front(a, *b);
	*b = first->next;
	free(first);
}

void	push_b(t_list **a, t_list **b)
{
	push_a(b, a);
}