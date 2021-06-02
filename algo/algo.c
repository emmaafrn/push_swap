#include "../push_swap.h"

int	get_smaller(t_list **a)
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

void	get_the_two_smallest(t_list **a, t_list **b, int smaller)
{
	while (ft_lstsize(*a) > 3)
	{
		while ((*a)->content != smaller)
		{
			if (min_distance(*a, smaller))
			{
				rotate_a(a);
				printf("ra\n");
			}
			else
			{
				rev_rotate_a(a);
				printf("rra\n");
			}
		}
		push_b(a, b);
		printf("pb\n");
		smaller = get_smaller(a);
	}
}

void	four_five(t_list **a)
{
	t_list	*tmp;
	t_list	*b;
	int		smaller;

	b = NULL;
	smaller = get_smaller(a);
	tmp = *a;
	get_the_two_smallest(a, &b, smaller);
	three_numbers(a, 5);
	while (b)
	{
		push_a(a, &b);
		printf("pa\n");
	}
}

void	wich_algo(t_list **a, t_list **b, t_chunks *c_struct)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
		two_numbers(a);
	else if (size == 3)
		three_numbers(a, 3);
	else if (size == 4 || size == 5)
		four_five(a);
	else if (size > 5)
	{
		limits(a, c_struct);
		if (c_struct->chunk_limit == NULL)
		{
			printf("Error\n");
			return ;
		}
		push_under_limits(a, b, c_struct->chunk_limit, c_struct);
		sort_a(a, b);
	}
}
