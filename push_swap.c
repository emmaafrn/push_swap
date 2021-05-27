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
				printf("Error\n");
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
	t_list	*a;
	t_list	*b;
	t_chunks c_struct;

	if (argc <= 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	b = 0;
	c_struct.divisor = 0;
	a = argv_to_lst(argv, argc); 
	// rev_rotate_a(&a);
	// rotate_a(&a);
	check_duplicates(a);
	algo(&a, &b, &c_struct);
	// print_lst(a);
	// while (a != NULL)
	// {
	// 	printf("a = %d\n", a->content);
	// 	a = a->next;
	// }
}
