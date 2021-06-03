#include "push_swap.h"

int	is_it_sorted(t_list **a)
{
	t_list	*dup;
	t_list	*orig;

	orig = lst_dup(*a);
	dup = orig;
	while (dup->next)
	{
		if (dup->next->content <= dup->content)
		{
			ft_lstclear(&orig);
			return (0);
		}
		dup = dup->next;
	}
	ft_lstclear(&orig);
	return (1);
}
