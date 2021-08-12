#include "libft.h"
#include "push_swap.h"

/* Puts list B in order to push an element*/
static void	rotate_for_tmp(t_list **to, t_list *tmp, t_cmd **cmds)
{
	int			min;
	int			max;

	max = find_max(*to);
	min = find_min(*to);
	if ((*to)->next)
	{
		if (tmp->num < min || tmp->num > max)
			order_list(to, 'b', cmds);
		else
		{
			if (closer_to_start(tmp->num, *to, 'b'))
				while (!((*to)->prev->num > tmp->num && (*to)->num < tmp->num))
					rotate(to, 'b', cmds);
			else
				while (!((*to)->prev->num > tmp->num && (*to)->num < tmp->num))
					rev_rotate(to, 'b', cmds);
		}
	}
}

/* Function that adds first and second element to the list*/
static void	first_second_elt(t_list **to, t_list *tmp)
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

static void	link_new_elt(t_list *tmp, t_list **to)
{
	tmp->next = *to;
	tmp->prev = (*to)->prev;
	(*to)->top = 0;
	(*to)->prev = tmp;
	*to = tmp;
	tmp = tmp->prev;
	tmp->next = *to;
}

/* Push to B operation */
void	push_b(t_list **from, t_list **to, t_cmd **cmds)
{
	t_list		*tmp;

	if (!*from)
		return ;
	tmp = *from;
	if (*from != (*from)->next)
	{
		(*from)->next->top = 1;
		(*from)->next->prev = (*from)->prev;
		(*from)->prev->next = (*from)->next;
		*from = (*from)->next;
	}
	else
		*from = NULL;
	if (*to == NULL || *to == (*to)->next)
		first_second_elt(to, tmp);
	else
	{
		rotate_for_tmp(to, tmp, cmds);
		link_new_elt(tmp, to);
	}
	add_cmd("pb", cmds);
}

/* Push operation (for A and checker) */
void	push(t_list **from, t_list **to, t_cmd **cmds, char list)
{
	t_list		*tmp;

	if (!*from)
		return ;
	tmp = *from;
	tmp->order = 1;
	if (*from != (*from)->next)
	{
		(*from)->next->top = 1;
		(*from)->next->prev = (*from)->prev;
		(*from)->prev->next = (*from)->next;
		*from = (*from)->next;
	}
	else
		*from = NULL;
	if (*to == NULL || *to == (*to)->next)
		first_second_elt(to, tmp);
	else
		link_new_elt(tmp, to);
	if (list == 'a')
		add_cmd("pa", cmds);
	else
		add_cmd("pb", cmds);
}
