#include "../push_swap.h"

void	rev_rotate_or_rotate(t_list **a, t_list *lst)
{
	if (min_distance(*a, lst->content))
	{
		while ((*a)->content != lst->content)
		{
			rotate_a(a);
			printf("ra\n");
		}
	}
	else
	{
		while ((*a)->content != lst->content)
		{
			rev_rotate_a(a);
			printf("rra\n");
		}
	}
}
