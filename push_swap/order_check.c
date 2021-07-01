#include "libft.h"
#include "push_swap.h"

int		in_order(t_list *start)
{
	while (start->next)
	{
		if (start->num > start->next->num)
			return (0);
		start = start->next;
	}
	return (1);
}

int		find_min(t_list *current)
{
	int		min_n;
	//static int i = 0;

	//printf("\n(%d) FIND MIN\n", i);
	min_n = current->num;
	while (current)
	{
		//printf("num = %d\n", current->num);
		if (min_n > current->num)
			min_n = current->num;
		current = current->next;
	}
	//printf("\n(%d) MIN = %d\n", i++, min_n);
	return (min_n);
}

int		find_max(t_list *current)
{
	int		max_n;

	max_n = current->num;
	while (current)
	{
		if (max_n < current->num)
			max_n = current->num;
		current = current->next;
	}
	return (max_n);
}

int			closer_to_start(int min, t_list *list)
{
	int		last;
	int		found;
	//static int i = 0;

	last = 0;
	found = 0;
	//printf("\n(%d) Looking for : %d\n", i, min);
	//printf("\nlist->num = %d, list != NULL : %d\n", list->num, list != NULL);
	while (list && ++last)
	{
		//printf("num[%d] = %d\n", last, list->num);
		if (list->num == min)
			found = last;
		list = list->next;
	}
	//printf("\n(%d) CLOSER TO START :: last = %d, found = %d, (last / 2) > found = %d\n", i++, last, found, (last / 2) > found);
	return ((last / 2) > found);
}

void		order_list(t_list **list, char list_name)
{
	if (closer_to_start(find_min(*list), *list))
		while (!in_order(*list))
			rotate(list, list_name);
	else
		while (!in_order(*list))
			rev_rotate(list, list_name);
}

int		is_last(t_list *list, int n)
{
	while (list->next)
		list = list->next;
	if (list->num < n)
		return (1);
	return (0);
}
