#include "../push_swap.h"

void	push_a(t_list **a, t_list **b)
{
	t_list	*first;

	if (!(*b))
		return ;
	first = *b;
	*b = first->next;
	first->next = *a;
	*a = first;
}

void	push_b(t_list **a, t_list **b)
{
	if (!(*a))
		return ;
	push_a(b, a);
}