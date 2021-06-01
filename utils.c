#include "push_swap.h"

void	print_lst(t_list *lst)
{
	t_list	*newlst;

	newlst = lst;
	while (newlst)
	{
		printf("%d\n", newlst->content);
		newlst = newlst->next;
	}
}

t_list	*lst_dup(t_list *lst)
{
	t_list	*dup;
	t_list	*start;
	t_list	*new;
	int		i;

	i = 0;
	dup = 0;
	start = lst;
	while (lst != NULL)
	{
		new = ft_lstnew(lst->content);
		ft_lstadd_back(&dup, new);
		i++;
		lst = lst->next;
	}
	lst = start;
	return (dup);
}

void	sorting_lst(t_list **a, t_list *b, int sort, t_list *start)
{
	int	tmp;

	tmp = (*a)->content;
	while (sort == 1 && *a != NULL)
	{
		sort = 0;
		while (*a != NULL)
		{
			b = start;
			while (b != NULL)
			{
				if ((*a)->next != NULL && (*a)->next->content < (*a)->content)
				{
					tmp = (*a)->next->content;
					(*a)->next->content = (*a)->content;
					(*a)->content = tmp;
					sort = 1;
				}
				b = b->next;
			}
			*a = (*a)->next;
		}
		*a = start;
	}
}

void	pre_sort(t_list **a)
{
	t_list	*b;
	t_list	*start;
	int		sort;

	b = *a;
	sort = 1;
	start = *a;
	sorting_lst(a, b, sort, start);
}
