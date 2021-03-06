#include "push_swap.h"

t_list	*argv_to_lst(char **argv, int argc)
{
	t_list	*new;
	t_list	*lst;
	int		res;
	int		i;

	i = 1;
	lst = NULL;
	res = 0;
	while (i < argc)
	{
		res = ft_atoi(argv[i]);
		new = ft_lstnew(res);
		ft_lstadd_back(&lst, new);
		i++;
	}
	return (lst);
}

void	check_duplicates(t_list *a)
{
	t_list	*it;
	t_list	*first;

	first = a;
	it = a->next;
	if (ft_lstsize(a) == 1)
		return ;
	while (a)
	{
		while (it)
		{
			if (a->content == it->content)
            {
                write(2, "Error\n", 6);
                exit(0);
            }
			it = it->next;
		}
		a = a->next;
		if (a)
			it = a->next;
	}
	a = first;
}

int	main(int argc, char **argv)
{
	t_list		*a;
	t_list		*b;
	t_chunks	c_struct;

	if (argc <= 1)
		return (0);
	b = 0;
	c_struct.divisor = 0;
	a = argv_to_lst(argv, argc);
	if (a == NULL)
		return (0);
	check_duplicates(a);
	if (is_it_sorted(&a))
	{
		ft_lstclear(&a);
		exit(0);
	}
	wich_algo(&a, &b, &c_struct);
	ft_lstclear(&a);
	if (c_struct.chunk_limit)
		free(c_struct.chunk_limit);
}
