#include "libft.h"
#include "push_swap.h"

static void	rotate_for_tmp(t_list **to, t_list *tmp)
{
	int			min;
	int			max;

	max = find_max(*to);
	min = find_min(*to);
	if ((*to)->next)
	{
		if (tmp->num < min || tmp->num > max)
			order_list(to, 'b');
		else
		{
			if (closer_to_start(tmp->num, *to))
				while (!((*to)->prev->num < tmp->num && (*to)->num > tmp->num))
					rotate(to, 'b');
			else
				while (!((*to)->prev->num < tmp->num && (*to)->num > tmp->num))
					rev_rotate(to, 'b');
		}
	}
}

void	first_second_elt(t_list **to, t_list *tmp)
{
	if (*to == NULL)
	{
		tmp->next = tmp;
		tmp->prev = tmp;
		*to = tmp;
	}
	else if (*to == (*to)->next)
	{
		tmp->next = *to;
		tmp->prev = *to;
		(*to)->top = 0;
		(*to)->prev = tmp;
		(*to)->next = tmp;
		*to = tmp;
	}
}

void	push_b(t_list **from, t_list **to)
{
	t_list		*tmp;

	tmp = *from;
	(*from)->next->top = 1;
	(*from)->next->prev = (*from)->prev;
	(*from)->prev->next = (*from)->next;
	*from = (*from)->next;
	if (*to == NULL || *to == (*to)->next)
		first_second_elt(to, tmp);
	else
	{
		rotate_for_tmp(to, tmp);
		tmp->next = *to;
		tmp->prev = (*to)->prev;
		(*to)->top = 0;
		(*to)->prev = tmp;
		*to = tmp;
		tmp = tmp->prev;
		tmp->next = *to;
	}
	ft_putendl_fd("pb", 1);
}

void	push_a(t_list **from, t_list **to)
{
	t_list		*last;
	t_list		*tmp;

	tmp = *from;
	tmp->order = 1;
	if (*from != (*from)->next)
	{
		last = (*from)->prev;
		*from = (*from)->next;
		(*from)->top = 1;
		last->next = *from;
		(*from)->prev = last;
	}
	else
		*from = NULL;
	tmp->next = *to;
	tmp->prev = (*to)->prev;
	(*to)->top = 0;
	(*to)->prev = tmp;
	*to = tmp;
	tmp = tmp->prev;
	tmp->next = *to;
	ft_putendl_fd("pa", 1);
}
