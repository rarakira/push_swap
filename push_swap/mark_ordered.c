#include "push_swap.h"

static void	clean_order(t_list *list, int top)
{
	int		num;
	int		max;
	t_list	*tmp;

	num = list->num;
	tmp = list;
	max = top;
	while (top)
	{
		if ((top == max && list->order == top)
			|| (list->order == top && list->num <= num))
		{
			list->order = 1;
			num = list->num;
			top--;
		}
		else
			list->order = 0;
		list = list->prev;
		if (list == tmp)
			break ;
	}
}

static int	compare_to_prev(t_list *list, int num)
{
	t_list	*tmp;
	int		max;

	tmp = list;
	max = 1;
	while (list->order != 0)
	{
		if (list->num < num && list->order >= max)
			max = list->order + 1;
		list = list->prev;
		if (list == tmp)
			break ;
	}
	return (max);
}

void	mark_ordered(t_list *list)
{
	int		min;
	int		top;

	top = 0;
	min = find_min(list);
	while (list->num != min)
		list = list->next;
	while (list)
	{
		if (list->prev->order == 0)
			list->order = 1;
		else
			list->order = compare_to_prev(list->prev, list->num);
		if (list->order > top)
			top = list->order;
		list = list->next;
		if (list->num == min)
			break ;
	}
	clean_order(list->prev, top);
	mark_middle_nums(list);
	set_index(list, min);
}
