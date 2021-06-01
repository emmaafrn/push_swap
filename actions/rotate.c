#include "../push_swap.h"

void	rotate_a(t_list	**a)
{
	t_list	*first;
	t_list	*newfirst;
	int		lst_len;

	lst_len = ft_lstsize(*a);
	if (lst_len <= 1)
		return ;
	first = (*a);
	newfirst = (*a)->next;
	while ((*a)->next)
		(*a) = (*a)->next;
	(*a)->next = first;
	(*a)->next->next = NULL;
	*a = newfirst;
}

void	rotate_b(t_list	**b)
{
	rotate_a(b);
}

void	rotate_ab(t_list **a, t_list **b)
{
	rotate_a(a);
	rotate_b(b);
}
