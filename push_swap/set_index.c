#include "push_swap.h"

static int	all_indexed(t_list *list, int min)
{
	t_list	*start;

	start = list;
	while (list)
	{
		if (!list->index && list->num != min)
			return (0);
		list = list->next;
		if (start == list)
			break ;
	}
	return (1);
}

static int	find_next(t_list *current, int min, int smallest)
{
	int		next;
	t_list	*start;

	next = min;
	start = current;
	while (current)
	{
		if (next == min && !current->index && current->num > min
			&& current->num != smallest)
			next = current->num;
		if (!current->index && next > current->num && current->num != smallest)
			next = current->num;
		current = current->next;
		if (current == start)
			break ;
	}
	return (next);
}

void	set_index(t_list *list, int min)
{
	int		i;
	int		current;

	current = min;
	i = 0;
	while (!all_indexed(list, min))
	{
		current = find_next(list, current, min);
		while (list->num != current)
			list = list->next;
		list->index = ++i;
	}
}
