#include "../push_swap.h"

void	two_numbers(t_list	**a)
{
	if ((*a)->content > (*a)->next->content)
	{
		rotate_a(a);
		printf("ra\n");
	}
}

void	sort_three_numberss(t_list **a, int b, int a_bis, int c)
{
	if (a_bis > b && b < c && a_bis < c)
	{
		swap_a(*a);
		printf("sa\n");
	}
	if (a_bis > b && b > c)
	{
		swap_a(*a);
		rev_rotate_a(a);
		printf("sa\nrra\n");
	}
	if (a_bis > b && b < c && a_bis > c)
	{
		rotate_a(a);
		printf("ra\n");
	}
	if (a_bis < b && b > c && a_bis < c)
	{
		swap_a(*a);
		rotate_a(a);
		printf("sa\nra\n");
	}
}

void	three_numbers(t_list	**a, int size)
{
	int		a_bis;
	int		b;
	int		c;

	a_bis = (*a)->content;
	b = (*a)->next->content;
	c = (*a)->next->next->content;
	if ((*a)->content < (*a)->next->content < (*a)->next->next->content)
	{
		if (size == 3)
			exit(0);
	}
	sort_three_numberss(a, b, a_bis, c);
	if (a_bis < b && b > c && a_bis > c)
	{
		rev_rotate_a(a);
		printf("rra\n");
	}
}
