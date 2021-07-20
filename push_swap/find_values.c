#include "push_swap.h"

/* Find smallest number in list */
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

/* Find largest number in list */
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

/* If not init yet – find i, smallest and largest numbers in the list */
void	init_static_values(t_list *list, int *min, int *max)
{
	if (!(*min) && !(*max))
	{
		*min = find_min(list);
		*max = find_max(list);
	}
}

/* Counts number of elements in the list */
int	count_elements(t_list *list)
{
	int		count;
	t_list	*start;

	count = 0;
	start = list;
	while (list && ++count)
	{
		list = list->next;
		if (list == start)
			break ;
	}
	return (count);
}
