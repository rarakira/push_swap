#include "push_swap.h"

/* Returns number of actions (rotation) dst have to perform in order to align
with src */
static int	is_close(int index, t_list *dst)
{
	t_list	*tmp;
	int		i;

	tmp = dst;
	i = 0;
	if (dst->index > index)
	{
		while (++i)
		{
			tmp = tmp->next;
			if (tmp->index > dst->index || tmp == dst || tmp->index < index)
				break ;
		}
	}
	else
	{
		while (++i)
		{
			tmp = tmp->prev;
			if (tmp->index < dst->index || tmp == dst || tmp->index > index)
				break ;
		}
	}
	return (i);
}

/* Checks if there are elements in the beginning of src_list
that can be inserted in dst_list in less than N actions */
static int	check_next(t_list *src, t_list *dst, int *found, int n)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = src;
	while (++i < n + 2)
	{
		tmp = tmp->next;
		if ((!tmp->order && is_close(tmp->index, dst) < n))
			*found = 1;
		if ((!tmp->order && is_close(tmp->index, dst) < n) || tmp == src)
			break ;
	}
	return (i);
}

/* Checks if there are elements at the end of src_list
that can be inserted in dst_list in less than N actions */
static int	check_prev(t_list *src, t_list *dst, int *found, int n)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = src;
	while (++i < n + 2)
	{
		tmp = tmp->prev;
		if ((!tmp->order && is_close(tmp->index, dst) < n))
			*found = 1;
		if ((!tmp->order && is_close(tmp->index, dst) < n) || tmp == src)
			break ;
	}
	return (i);
}

/*
Finds element in src_list to push into dst_list.
Returns positive number if number is closer to the beginning of the list.
Returns negative number if number is closer to the end of the list.
*/
int	find_closer_number(t_list **src, t_list **dst)
{
	int		i;
	int		j;
	int		n;
	int		found;

	n = 2;
	found = 0;
	while (!found && n++)
	{
		if (!(*src)->order && (is_close((*src)->index, *dst) < n
				|| count_larger_than(*src, 0) == 1))
			return (0);
		i = check_next(*src, *dst, &found, n);
		j = check_prev(*src, *dst, &found, n);
	}
	if (i > j)
		return (j * -1);
	return (i);
}
