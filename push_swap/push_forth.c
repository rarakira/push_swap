#include "push_swap.h"

/* Returns the difference (positive number) between 2 numbers */
static int	index_dif(int this, int num)
{
	int			i;

	i = this - num;
	if (i < 0)
		return (i * -1);
	return (i);
}

/* Checks if next element will take less actions to be pushed to list_b
before the current element*/
static int	next_is_closer(t_list **start_a, t_list **start_b)
{
	int			n;
	t_list		*tmp;

	tmp = *start_a;
	if (!(*start_b))
		return (0);
	n = index_dif((*start_a)->index, (*start_b)->index);
	tmp = (*start_a)->next;
	if (!tmp->order && n > index_dif(tmp->index, (*start_b)->index))
		return (1);
	tmp = (*start_a)->prev;
	if (!tmp->order && n > index_dif(tmp->index, (*start_b)->index))
		return (-1);
	return (0);
}

/* Push number to list B if it is not ordered and is greater than threshold.
Rotate A otherwise. */
void	push_forth(t_list **start_a, t_list **start_b, t_cmd **cmds)
{
	static int	i;
	int			f;

	if (!(*start_a)->order && (!*start_b || i++ < 10))
		push_b(start_a, start_b, cmds);
	else
	{
		f = find_closer_number(start_a, start_b);
		if (f < 0)
			while (f++ < 0)
				rev_rotate(start_a, 'a', cmds);
		else if (f > 0)
			while (f-- > 0)
				rotate(start_a, 'a', cmds);
		if (next_is_closer(start_a, start_b) > 0)
			while (next_is_closer(start_a, start_b) > 0)
				swap(start_a, 'a', cmds);
		else if (next_is_closer(start_a, start_b) < 0)
			while (next_is_closer(start_a, start_b) < 0)
				rev_rotate(start_a, 'a', cmds);
		push_b(start_a, start_b, cmds);
	}
}
