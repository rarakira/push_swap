#include "push_swap.h"

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

int	find_min(t_list *current)
{
	int		min_n;

	min_n = current->num;
	while (current)
	{
		if (min_n > current->num)
			min_n = current->num;
		current = current->next;
		if (current == current->next || current->top)
			break ;
	}
	return (min_n);
}

int	find_max(t_list *current)
{
	int		max_n;

	max_n = current->num;
	while (current)
	{
		if (max_n < current->num)
			max_n = current->num;
		current = current->next;
		if (current == current->next || current->top)
			break ;
	}
	return (max_n);
}

/*
int	closer_to_start(int min, t_list *list)
{
	int		last;
	int		found;

	last = 0;
	found = 0;
	while (list && ++last)
	{
		if (list->num == min)
			found = last;
		list = list->next;
		if (list->top)
			break ;
	}
	return ((last / 2) > found);
}
*/

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

int	is_last(t_list *list, int n)
{
	while (!list->next->top)
		list = list->next;
	if (list->num < n)
		return (1);
	return (0);
}
