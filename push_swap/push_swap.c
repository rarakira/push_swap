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
static void	push_back(t_list **start_a, t_list **start_b, int min_n)
{
	order_list(start_b, 'b');
	while (*start_b)
	{
		while (*start_b && (((*start_a)->num > (*start_b)->num
					&& (*start_a)->prev->num < (*start_b)->num)
				|| ((*start_a)->num == min_n
					&& is_last(*start_a, (*start_b)->num))))
			push_a(start_b, start_a);
		if (*start_b)
		{
			if (closer_to_start((*start_b)->num, *start_a, 'a'))
				rotate(start_a, 'a');
			else
				rev_rotate(start_a, 'a');
		}
	}
	order_list(start_a, 'a');
}

/* Returns N of elements in list that are greater than or equal to threshold */
static int	count_larger_than(t_list *start_a, int mid_n)
{
	int		n;

	n = 0;
	if (!(start_a->order) && start_a->num >= mid_n)
		n++;
	start_a = start_a->next;
	while (!start_a->top)
	{
		if (!(start_a->order) && start_a->num >= mid_n)
			n++;
		start_a = start_a->next;
	}
	return (n);
}

/* Push number to list B if it is not ordered and is greater than threshold.
Rotate A otherwise. */
static int	push_forth(t_list **start_a, t_list **start_b, int threshold, int i)
{
	if ((*start_a)->order || (*start_a)->num < threshold)
		rotate(start_a, 'a');
	else
		push_b(start_a, start_b);
	if (!count_larger_than(*start_a, threshold))
		i++;
	return (i);
}

//print_list(*start_a, "PUSH_SWAP A");
//print_list(start_b, "PUSH_SWAP B");
/* Push swap function – core algorithm of the program */
void	push_swap(t_list **start_a, int step, int parts)
{
	static t_list	*start_b;
	static int		min_n;
	static int		max_n;
	static int		i;

	init_min_max(*start_a, &min_n, &max_n);
	if (!i)
		i = init_i(parts);
	if (!start_b && in_order(*start_a, 'a'))
		return ;
	while ((i <= parts) && ((*start_a)->num != (*start_a)->next->next->num))
	{
		if (i < parts)
			i = push_forth(start_a, &start_b, max_n - (step * i), i);
		else
			i = push_forth(start_a, &start_b, min_n, i);
	}
	do_the_swapping(start_a);
	if (is_ordered(*start_a))
		push_back(start_a, &start_b, min_n);
	return (push_swap(start_a, step, parts));
}
