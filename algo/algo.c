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
	tri_tree_number(a);
	// printf ("a : ");
	// print_lst(*a);
	// printf ("b : ");
	// print_lst(b);
	while (b)
	{
		push_a(a, &b);
		printf("pa\n");
	}
}

void	algo(t_list	**a)
{
	if (ft_lstsize(*a) == 2)
		two_number(a);
	// printf("here\n");
	if (ft_lstsize(*a) == 3)
		tree_number(a);
	if (ft_lstsize(*a) >= 4)
		four_five(a);
}