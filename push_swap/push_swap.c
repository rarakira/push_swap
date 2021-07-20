#include "push_swap.h"

/* Checks if the element should be last in the 'to' list */
static int	is_last(t_list *to_list, int n)
{
	while (!to_list->next->top)
		to_list = to_list->next;
	if (to_list->num < n)
		return (1);
	return (0);
}

/* Push all elements from list B to list A and put list A in order. */
static void	push_back(t_list **start_a, t_list **start_b, int max_n,
t_cmd **cmds)
{
	do_the_swapping(start_a, cmds);
	order_list(start_a, 'a', cmds);
	if (*start_b)
		order_list(start_b, 'b', cmds);
	while (*start_b)
	{
		while (*start_b && ((*start_a)->index == (*start_b)->index + 1
				|| ((*start_b)->num == max_n
					&& is_last(*start_a, (*start_b)->num))))
			push_a(start_b, start_a, cmds);
		if (*start_b)
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
int	count_larger_than(t_list *start_a, int threshold)
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

void	push_swap(t_list **start_a, int n_el, t_cmd **cmds)
{
	static t_list	*start_b;
	static int		min_n;
	static int		max_n;

	init_static_values(*start_a, &min_n, &max_n);
	if (!start_b && in_order(*start_a, 'a'))
		return ;
	while (count_larger_than(*start_a, 0))
		push_forth(start_a, &start_b, cmds);
	push_back(start_a, &start_b, max_n, cmds);
	return (push_swap(start_a, n_el, cmds));
}
