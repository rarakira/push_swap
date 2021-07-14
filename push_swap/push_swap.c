#include "push_swap.h"

/* Checks if the element should be last in the 'to' list */
static int	is_last(t_list *list, int n)
{
	while (!list->next->top)
		list = list->next;
	if (list->num < n)
		return (1);
	return (0);
}

/* Push all elements from list B to list A and put list A in order. */
static void	push_back(t_list **start_a, t_list **start_b, int min_n,
t_cmd **cmds)
{
	if (*start_b)
		order_list(start_b, 'b', cmds);
	do_the_swapping(start_a, cmds);
	order_list(start_a, 'a', cmds);
	while (*start_b)
	{
		while (*start_b && (*start_a)->prev->prev->order != 2
			&& (((*start_a)->num > (*start_b)->num
					&& (*start_a)->prev->num < (*start_b)->num)
				|| ((*start_a)->num == min_n
					&& is_last(*start_a, (*start_b)->num))))
			push_a(start_b, start_a, cmds);
		if (*start_b && (*start_a)->prev->prev->order != 2)
		{
			if (closer_to_start((*start_b)->num, *start_a, 'a'))
				rotate(start_a, 'a', cmds);
			else
				rev_rotate(start_a, 'a', cmds);
		}
	}
	order_list(start_a, 'a', cmds);
}

/* Returns N of elements in list that are greater than or equal to threshold */
static int	count_larger_than(t_list *start_a, int threshold)
{
	int		n;

	n = 0;
	if (!(start_a->order) && start_a->index >= threshold)
		n++;
	start_a = start_a->next;
	while (!start_a->top)
	{
		if (!(start_a->order) && start_a->index >= threshold)
			n++;
		start_a = start_a->next;
	}
	return (n);
}

void	push_swap(t_list **start_a, int steps, int parts, t_cmd **cmds)
{
	static t_list	*start_b;
	static int		min_n;
	static int		max_n;
	static int		i;

	max_n = init_static_values(*start_a, &min_n, &i, parts);
	if (!start_b && in_order(*start_a, 'a'))
		return ;
	while (i <= parts)
	{
		if (i < parts)
		{
			if (count_larger_than(*start_a, (steps * parts) - (steps * i)) < 5)
				push_forth(start_a, &start_b, (steps * parts) - (steps * i) - 10, cmds);
			else
				push_forth(start_a, &start_b, (steps * parts) - (steps * i), cmds);
		}
		else
			push_forth(start_a, &start_b, 0, cmds);
		if ((i < parts && !count_larger_than(*start_a, (steps * parts) - (steps * i)))
			|| (i == parts && !count_larger_than(*start_a, 0)))
			i++;
	}
	push_back(start_a, &start_b, min_n, cmds);
	return (push_swap(start_a, steps, parts, cmds));
}

/*
while (i <= parts)
	{
		if (i < parts)
		{
			push_forth(start_a, &start_b, count / i, cmds);
		}
		else
			push_forth(start_a, &start_b, min_n, cmds);
		if ((i < parts && !count_larger_than(*start_a, count / i))
			|| (i == parts && !count_larger_than(*start_a, min_n)))
			i++;
	}
*/
