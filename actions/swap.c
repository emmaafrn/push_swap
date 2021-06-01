#include "../push_swap.h"

void	swap_b(t_list *b)
{
	t_list	*first;
	int		tmp;
	int		len;

	first = b;
	len = ft_lstsize(b);
	if (len < 2)
		return ;
	tmp = b->content;
	b->content = b->next->content;
	b->next->content = tmp;
}

void	swap_a(t_list *a)
{
	swap_b(a);
}

void	swap_ab(t_list *a, t_list *b)
{
	swap_a(a);
	swap_b(b);
}
