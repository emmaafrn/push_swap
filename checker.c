#include "push_swap.h"

int	is_it_sorted(t_list **a)
{
	t_list	*dup;

	dup = lst_dup(*a);
	while (dup->next)
	{
		if (dup->next->content <= dup->content)
			return (0);
		dup = dup->next;
	}
	ft_lstclear(&dup);
	return (1);
}
