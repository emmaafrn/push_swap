#include "../push_swap.h"

int		get_smaller(t_list **a)
{
	t_list	*tmp;
	int		smaller;

	smaller = (*a)->content;
	tmp = *a;

	while (tmp->next)
	{
		if (tmp->content < smaller)
			smaller = tmp->content;
		tmp = tmp->next;
	}
	if (tmp->content < smaller)
			smaller = tmp->content;
	return (smaller);
}

void	four_five(t_list **a)
{
	t_list	*tmp;
	t_list	*b;
	int		smaller;

	smaller = get_smaller(a);
	tmp = *a;
	while (ft_lstsize(*a) > 3)
	{
		while ((*a)->content != smaller)
		{
			rotate_a(a);
			printf("ra\n");
		}
		push_b(a, &b);
		printf("pb\n");
		smaller = get_smaller(a);
	}
	tri_three_number(a);
	while (b)
	{
		push_a(a, &b);
		printf("pa\n");
	}
}

void	algo(t_list	**a, t_list **b, t_chunks *c_struct)
{
	int size;

	size = ft_lstsize(*a);
	if (size == 2)
		two_number(a);
	if (size == 3)
		three_number(a);
	if (size == 4 || size == 5)
		four_five(a);
	if (size > 5)
	{
		limits(a, c_struct);
		push_values_under_limits(a, b, c_struct->chunk_limit, c_struct);
		sort_a(a, b);
	}
}