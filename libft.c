#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	int			s;
	long long	result;

	i = 0;
	s = 1;
	result = 0;
	while ((nptr[i] >= 8 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			s = s * (-1);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + nptr[i] - '0';
		i++;
	}
	if (nptr[i] != '\0')
	{
		printf("Error\n");
		exit(0);
	}
	result = result * s;
	return ((int)result);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*ok;

	ok = (*lst);
	while (ok != NULL)
	{
		ok = (*lst)->next;
		free((*lst));
		(*lst) = ok;
	}
	(*lst) = NULL;
}
