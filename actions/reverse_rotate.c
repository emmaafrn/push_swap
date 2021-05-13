#include "../push_swap.h"

void		rev_rotate_a(t_list **a)
{
	t_list	*tmp;
	t_list	*before;
	int		lst_len;

	lst_len = ft_lstsize(*a);
	if (lst_len <= 1)
		return ;
	tmp = *a;
	while (tmp->next)
	{
		before = tmp;
		tmp = tmp->next;
	}
	before->next = NULL;
	tmp->next = *a;
	*a = tmp;
}

void		rev_rotate_b(t_list **b)
{
	rev_rotate_a(b);
}

void		rev_rotate_a_and_b(t_list **a, t_list **b)
{
	rev_rotate_a(a);
	rev_rotate_b(b);
}