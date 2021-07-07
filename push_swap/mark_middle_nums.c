#include "push_swap.h"

/* Compare number with ordered and mark with '2' */
static void	mark_middle(t_list *list, int min, int max)
{
	if (min < max)
	{
		while (!(list->num < max && list->num > min) && !list->order)
			list = list->prev;
		if (list->num < max && list->num > min)
			list->order = 2;
	}
	else
	{
		while (!(list->num > min) && !list->order)
			list = list->prev;
		if (list->num > min)
			list->order = 2;
	}	
}

/* Find next ordered number */
static int	find_next(t_list *list)
{
	while (list->order != 1)
		list = list->next;
	return (list->num);
}

/* Mark numbers that need swapping (order = 2) */
void	mark_middle_nums(t_list *list)
{
	int		min;
	int		max;
	t_list	*current;

	current = list;
	while (list)
	{
		if (list->order == 1)
		{
			min = list->num;
			max = find_next(list->next);
			mark_middle(list->prev, min, max);
			list = list->next;
		}
		else
			list = list->next;
		if (list == current)
			break ;
	}
}
