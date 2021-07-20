#include "push_swap.h"

/* Returns the difference (positive number) between 2 numbers */
static int	check_closest(int this, int num)
{
	int			i;

	i = this - num;
	if (i < 0)
		return (i * -1);
	return (i);
}

/* Checks if next element will take less actions to be pushed to list_b
before the current element*/
static int	next_is_closer(t_list **start_a, t_list **start_b, int threshold)
{
	int			n;
	t_list		*tmp;

	tmp = *start_a;
	if (!(*start_b))
		return (0);
	n = check_closest((*start_a)->num, (*start_b)->num);
	tmp = tmp->next;
	if (tmp->order || tmp->num < threshold
		|| n < check_closest(tmp->num, (*start_b)->num))
		return (0);
	return (1);
}

/* Push number to list B if it is not ordered and is greater than threshold.
Rotate A otherwise. */
void	push_forth(t_list **start_a, t_list **start_b, int threshold,
t_cmd **cmds)
{
	if ((*start_a)->order || (*start_a)->num < threshold)
		rotate(start_a, 'a', cmds);
	else
	{
		if (next_is_closer(start_a, start_b, threshold))
			swap(start_a, 'a', cmds);
		push_b(start_a, start_b, cmds);
	}
}
