#include "../push_swap.h"

void	two_number(t_list	**a)
{
	if ((*a)->content > (*a)->next->content)
	{
		rotate_a(a);
		printf("ra\n");
	}
	exit(0);
}

void	tree_number(t_list	**a)
{
	int		a_bis;
	int		b;
	int		c;

	a_bis = (*a)->content;
	b = (*a)->next->content;
	c = (*a)->next->next->content;
	if ((*a)->content > (*a)->next->content > (*a)->next->next->content)
		exit(0);
	if (a_bis > b && b < c && a_bis < c)
	{
		swap_a(*a);
		printf("sa\n");
		print_lst(*a);
	}
	if (a_bis > b && b > c)
	{
		swap_a(*a);
		rev_rotate_a(a);
		printf("sa\nrra\n");
		print_lst(*a);
	}
	if (a_bis > b && b < c && a_bis > c)
	{
		rotate_a(a);
		printf("ra\n");
		print_lst(*a);
	}
	if (a_bis < b && b > c && a_bis < c)
	{
		swap_a(*a);
		rotate_a(a);
		printf("sa\nra\n");
		print_lst(*a);
	}
	if (a_bis < b && b > c && a_bis > c)
	{
		rev_rotate_a(a);
		printf("rra\n");
		print_lst(*a);
	}
	exit(0);
}

void	algo(t_list	**a, t_list	**b)
{
	if (ft_lstsize(*a) == 2)
		two_number(a);
	// printf("here\n");
	if (ft_lstsize(*a) == 3)
		tree_number(a);
}