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

/* Find smallest and largest numbers in list */
void	init_min_max(t_list *list, int *min, int *max)
{
	if (!(*min) && !(*max))
	{
		*min = find_min(list);
		*max = find_max(list);
	}
}

/* i = 1 for small lists, i = 2 for large */
int	init_i(int parts)
{
	int		i;

	if (parts > 5)
		i = 2;
	else
		i = 1;
	return (i);
}

/*
Counts parts for the list and the size of step.

For lists smaller than 20: parts = 1
For lists smaller than 50: parts = 2
For lists smaller than 300: parts = (count / 15)
For larger lists: parts = (count / 35)
*/
int	count_parts(t_list *list, int *parts)
{
	int		count;
	int		step;
	int		min_n;
	int		max_n;

	min_n = find_min(list);
	max_n = find_max(list);
	count = 0;
	while (!list->next->top && ++count)
		list = list->next;
	if (count < 20)
		*parts = 1;
	else if (count < 50)
		*parts = 2;
	else if (count < 150)
		*parts = count / 15;
	else
		*parts = count / 40;
	step = (max_n - min_n) / (*parts);
	return (step);
}
