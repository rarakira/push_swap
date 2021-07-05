#include "push_swap.h"

static void	push_back(t_list **start_a, t_list **start_b, int min_n)
{
	order_list(start_b, 'b');
	while (*start_b)
	{
		while (*start_b && (*start_a)->num > (*start_b)->num
			&& (*start_a)->prev->num < (*start_b)->num)
			push_a(start_b, start_a);
		rotate(start_a, 'a');
		while (*start_b && (*start_a)->num == min_n
			&& is_last(*start_a, (*start_b)->num))
		{
			push_a(start_b, start_a);
			rotate(start_a, 'a');
		}
	}
	order_list(start_a, 'a');
}

static int	count_larger_than(t_list *start_a, int mid_n)
{
	int		n;

	n = 0;
	if (!start_a->order && start_a->num >= mid_n)
		n++;
	start_a = start_a->next;
	while (!start_a->top)
	{
		if (!start_a->order && start_a->num >= mid_n)
			n++;
		start_a = start_a->next;
	}
	return (n);
}

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

void	push_swap(t_list **start_a, int step, int parts)
{
	static t_list	*start_b;
	static int		min_n;
	static int		max_n;
	static int		i;

	init_min_max(*start_a, &min_n, &max_n);
	if (!i)
		i = init_i(parts);
	if (!start_b && in_order(*start_a))
		return ;
	while ((i < parts) && ((*start_a)->num != (*start_a)->next->next->num))
		i = push_forth(start_a, &start_b, max_n - (step * i), i);
	if ((*start_a)->order)
		rotate(start_a, 'a');
	else
		push_b(start_a, &start_b);
	if (start_b && is_ordered(*start_a))
		push_back(start_a, &start_b, min_n);
	return (push_swap(start_a, step, parts));
}
