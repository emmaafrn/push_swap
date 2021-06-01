#include "../push_swap.h"

void	compared_to_min_value(t_list **a, t_list **b, int min)
{
	if (min_distance(*a, min))
	{
		while ((*a)->content != min)
		{
			rotate_a(a);
			printf("ra\n");
		}
	}
	else
	{
		while ((*a)->content != min)
		{
			rev_rotate_a(a);
			printf("rra\n");
		}
	}
	push_a(a, b);
	printf("pa\n");
}

void	compared_to_first_values(t_list **a, t_list **b)
{
	while (ft_lstlast(*a)->content > (*b)->content)
	{
		rev_rotate_a(a);
		printf("rra\n");
	}
	push_a(a, b);
	printf("pa\n");
}

void	sort_a(t_list **a, t_list **b)
{
	t_list	*dup;
	int		min;

	min = (*a)->content;
	while (ft_lstsize(*b) > 0)
	{
		while ((*a)->content < (*b)->content)
		{
			rotate_a(a);
			printf("ra\n");
		}
		if ((*b)->content < min)
			compared_to_min_value(a, b, min);
		else if ((*b)->content < (*a)->content)
			compared_to_first_values(a, b);
		dup = lst_dup(*a);
		min = find_min_value(dup, min);
		ft_lstclear(&dup);
	}
	while (ft_lstlast(*a)->content < (*a)->content)
	{
		rev_rotate_a(a);
		printf("rra\n");
	}
}
