#include "../push_swap.h"

int	find_min_value(t_list *lst, int min)
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

int	min_distance(t_list *lst, int min)
{
	int		i;
	t_list	*start;

	i = 0;
	start = lst;
	while (lst && lst->content != min)
	{
		lst = lst->next;
		i++;
	}
	lst = start;
	if (i <= (ft_lstsize(lst) / 2))
		return (1);
	else
		return (0);
}

int	*find_limits(t_list *temp, int len_a, int *limits, t_chunks *c_struct)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (limits != NULL)
		free(limits);
	limits = malloc(c_struct->divisor * sizeof(int));
	if (limits == 0)
		return (NULL);
	while (++i <= len_a && j < c_struct->divisor)
	{
		if (j < c_struct->divisor && i % (len_a / c_struct->divisor) == 0)
			limits[j++] = temp->content;
		temp = temp->next;
	}
	if ((len_a % c_struct->divisor) > 0)
	{
		while (temp->next != NULL)
			temp = temp->next;
		limits[--j] = temp->content;
		j++;
	}
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
	if (len_a >= 500)
		c_struct->divisor = 11;
	else if (len_a >= 100)
		c_struct->divisor = 5;
	else if (len_a >= 50)
		c_struct->divisor = 4;
	else if (len_a >= 20)
		c_struct->divisor = 3;
	else
		c_struct->divisor = 2;
	c_struct->chunk_limit = find_limits(temp, len_a,
			c_struct->chunk_limit, c_struct);
	ft_lstclear(&temp);
	if (c_struct->chunk_limit == NULL)
		return ;
}

void	push_under_limits(t_list **a, t_list **b,
		int *limits, t_chunks *c_struct)
{
	int		i;
	t_list	*dup;

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
	ft_lstclear(&dup);
}
