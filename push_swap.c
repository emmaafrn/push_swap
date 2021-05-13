#include "push_swap.h"

t_list		*argv_to_lst(char **argv, int argc)
{
	t_list	*new;
	t_list	*lst;
	int		res;
	int		i;

	i = 1;
	res = 0;
	while (i < argc)
	{
		res = ft_atoi(argv[i]);
		printf("res %d\n", res);
		new = ft_lstnew(res);
		printf("new = %d\n", new->content);
		ft_lstadd_back(&lst, new);
		i++;
	}
	new = lst;
	while (lst != NULL)
	{
		printf("content = %d\n", lst->content);
		lst = lst->next;
	}
	lst = new;
	return (lst);
}

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
	while (b != NULL)
	{
		printf("b = %d\n", b->content);
		b = b->next;
	}
	b = first;
}


int	main(int argc, char **argv)
{
	t_list	*a;

	if (argc <= 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	a = argv_to_lst(argv, argc); 
	swap_b(a);
}