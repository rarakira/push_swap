#include "push_swap.h"

void	order_list(t_list **list, char list_name)
{
	if (closer_to_start(find_min(*list), *list))
		while (!in_order(*list))
			rotate(list, list_name);
	else
		while (!in_order(*list))
			rev_rotate(list, list_name);
}

int	is_ordered(t_list *start)
{
	int		min;
	int		max;

	min = find_min(start);
	max = find_max(start);
	while (start)
	{
		if (start->num > start->next->num
			&& !(start->num == max && start->next->num == min))
			return (0);
		start = start->next;
		if (start->top)
			break ;
	}
	return (1);
}

int	in_order(t_list *start)
{
	while (!start->next->top)
	{
		if (start->num > start->next->num)
			return (0);
		start = start->next;
	}
	return (1);
}

int	closer_to_start(int num, t_list *list)
{
	t_list		*first;
	int			next;
	int			prev;

	first = list;
	next = 0;
	prev = 0;
	while (list && ++next)
	{
		if (list->num == num || (list->prev->num < num && list->num > num))
			break ;
		list = list->next;
		if (list->top)
			break ;
	}
	while (first && ++prev)
	{
		if (first->num == num || (first->prev->num < num && first->num > num))
			break ;
		first = first->prev;
		if (first->top)
			break ;
	}
	return (next < prev);
}
