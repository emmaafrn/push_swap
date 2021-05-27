#include "../push_swap.h"

int		find_min_value(t_list *lst, int min)
{
	t_list	*start;

	start = lst;
	while (lst)
	{
		if (lst->content < min)
			min = lst->content;
		lst = lst->next;
	}
	lst = start;
	return (min);
}


int		*find_limits(t_list *temp, int len_a, int *limits, t_chunks *c_struct)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	limits = malloc(c_struct->divisor * sizeof(int));
	if (limits == 0)
		return (NULL);
	while (++i <= len_a && j < c_struct->divisor)
	{
		if (j < c_struct->divisor && i % (len_a / c_struct->divisor) == 0)
		{
			limits[j] = temp->content;
			j++;
		}
		temp = temp->next;
	}
	if ((len_a % c_struct->divisor) > 0)
	{
		while (temp->next != NULL)
			temp = temp->next;
		limits[--j] = temp->content;
		j++;
	}
	// j = -1;
	// while (++j < c_struct->divisor)
	// 	printf("tab[%d] = %d\n", j, *limits[j]);
	ft_lstclear(&temp);
	return (limits);
}

void	limits(t_list **a, t_chunks *c_struct)
{
	t_list	*temp;
	int		len_a;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len_a = ft_lstsize(*a);
	temp = lst_dup(*a);
	pre_sort(&temp);
	// printf("len_a = %d\n", len_a);
	if (len_a >= 20)
		c_struct->divisor = 5;
	else if (len_a % 3 == 0 && len_a > 6)
		c_struct->divisor = 3;
	else
		c_struct->divisor = 2;
	// printf("divisor = %d\n", c_struct->divisor);
	c_struct->chunk_limit = find_limits(temp, len_a, c_struct->chunk_limit, c_struct);
	if (c_struct->chunk_limit == NULL)
		return ;
}

void	push_values_under_limits(t_list **a, t_list **b, int *limits, t_chunks *c_struct)
{
	int	i;
	t_list *dup;

	i = 0;
	while (i < c_struct->divisor)
	{
		dup = lst_dup(*a);
		while (dup)
		{
			if (dup->content < limits[i])
			{
				while ((*a)->content != dup->content)
				{
					rotate_a(a);
					printf("ra\n");
				}
				push_b(a, b);
				printf("pb\n");
			}
			dup = dup->next;
		}
		i++;
	}
	// printf("----b----\n");
	// print_lst(*b);
	// printf("----a----\n");
	// print_lst(*a);
}

void	sort_a(t_list **a, t_list **b)
{
	t_list	*dup;
	int		min;

	min = (*a)->content;
	while (ft_lstsize(*b) > 0)
	{
		while ((*a)->content < (*b)->content)
		{
			rotate_a(a);
			printf("ra\n");
		}
		if ((*b)->content < min)
		{
			while ((*a)->content != min)
			{
				rotate_a(a);
				printf("ra\n");
			}
			push_a(a, b);
			printf("pa\n");
		}
		else if ((*b)->content < (*a)->content)
		{
			while (ft_lstlast(*a)->content > (*b)->content)
			{
				rev_rotate_a(a);
				printf("rra\n");
			}
			push_a(a, b);
			printf("pa\n");
			rev_rotate_a(a);
			printf("rra\n");
		}
		dup = lst_dup(*a);
		min = find_min_value(dup, min);
		ft_lstclear(&dup);
	}
	while (ft_lstlast(*a)->content < (*a)->content)
	{
		rev_rotate_a(a);
		printf("rra\n");
	}
	// printf("----b----\n");
	// print_lst(*b);
	// printf("----a----\n");
	// print_lst(*a);
}