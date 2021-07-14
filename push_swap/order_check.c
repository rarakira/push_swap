#include "push_swap.h"

/* Puts the list in order*/
void	order_list(t_list **list, char list_name, t_cmd **cmds)
{
	int		n;

	if (*list == NULL)
		return ;
	if (list_name == 'a')
		n = find_min(*list);
	else
		n = find_max(*list);
	if (closer_to_start(n, *list, list_name))
		while (!in_order(*list, list_name))
			rotate(list, list_name, cmds);
	else
		while (!in_order(*list, list_name))
			rev_rotate(list, list_name, cmds);
}

/* Checks whether the list is ordered [MAX & MIN can be at any location] */
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

/* Checks whether the list is in order [from MIN to MAX] */
int	in_order(t_list *start, char list_name)
{
	if (list_name == 'a')
	{
		while (!start->next->top)
		{
			if (start->num > start->next->num)
				return (0);
			start = start->next;
		}
	}
	else
	{
		while (!start->next->top)
		{
			if (start->num < start->next->num)
				return (0);
			start = start->next;
		}
	}
	return (1);
}

/* Counts steps from current location to its ordered place

To count forwards: type = 1
To count backwards: type != 1 */
int	count_steps(t_list *list, char list_name, int num, int type)
{
	int		count;

	count = 0;
	while (list && ++count)
	{
		if (list_name == 'a')
			if (list->num == num || (list->prev->num < num && list->num > num))
				break ;
		if (list_name == 'b')
			if (list->num == num || (list->prev->num > num && list->num < num))
				break ;
		if (type == 1)
			list = list->next;
		else
			list = list->prev;
		if (list->top)
			break ;
	}
	return (count);
}

/* Checks if NUM is closer to beginning or end of the list */
int	closer_to_start(int num, t_list *list, char list_name)
{
	int			next;
	int			prev;

	next = count_steps(list, list_name, num, 1);
	prev = count_steps(list, list_name, num, 0);
	return (next < prev);
}
