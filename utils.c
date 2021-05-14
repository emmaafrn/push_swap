#include "push_swap.h"

void	print_lst(t_list	*lst)
{
	t_list	*newlst;

	newlst = lst;
	while (newlst)
	{
	// return ;
		printf("%d\n", newlst->content);
		newlst = newlst->next;
	}
}