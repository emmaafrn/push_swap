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
		// printf("res %d\n", res);
		new = ft_lstnew(res);
		ft_lstadd_back(&lst, new);
		i++;
	}
	// lst = lst->next;
	return (lst);
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
	// rev_rotate_a(&a);
	rotate_a(&a);
	while (a != NULL)
	{
		printf("a = %d\n", a->content);
		a = a->next;
	}
}
