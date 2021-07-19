#include "push_swap.h"

/* Returns the difference (positive number) between 2 numbers */
//static int	index_dif(int this, int num)
//{
//	int			i;
//
//	i = this - num;
//	if (i < 0)
//		return (i * -1);
//	return (i);
//}

/* Checks if next element will take less actions to be pushed to list_b
before the current element*/
//static int	next_is_closer(t_list **start_a, t_list **start_b)
//{
//	int			n;
//	t_list		*tmp;
//
//	tmp = *start_a;
//	if (!(*start_b))
//		return (0);
//	n = index_dif((*start_a)->index, (*start_b)->index);
//	tmp = (*start_a)->next;
//	if (!tmp->order && n > index_dif(tmp->index, (*start_b)->index))
//		return (1);
//	tmp = (*start_a)->prev;
//	if (!tmp->order && n > index_dif(tmp->index, (*start_b)->index))
//		return (1);
//	return (0);
//}

//printf("1 : index = %d :\ntmp->next->index = %d > dest->index = %d\n", index, tmp->next->index, dest->index);
//printf("0 : index = %d > dest->index = %d\n", index, dest->index);
//printf("IS_CLOSE : %d\n", i);
static int	is_close(int index, t_list *dst)
{
	t_list	*tmp;
	int		i;

	tmp = dst;
	i = 0;
	//printf("IS_CLOSE : index = %d > dst->index = %d\n", index, dst->index);
	//print_list(dst, "DEST");
	if (dst->index > index)
	{
		while (++i)
		{
			if (tmp->next->index > dst->index)
				break ;
			tmp = tmp->next;
			if (tmp == dst || tmp->index < index)
				break ;
		}
	}
	else
	{
		while (++i)
		{
			if (tmp->prev->index < dst->index)
				break ;
			tmp = tmp->prev;
			if (tmp == dst || tmp->index > index)
				break ;
		}
	}
	//printf("IS_CLOSE : %d\n", i);
	return (i);
}

void	rotate_to_closest(t_list **src, t_list **dst, t_cmd **cmds)
{
	if (is_close((*src)->next->index, *dst)
		> is_close((*src)->prev->index, *dst) && !(*src)->prev->order)
		rotate(src, 'a', cmds);
	else
		swap(src, 'a', cmds);
}

//printf("(i = %d) n = %d | is_close = %d || dst = %d | tmp = %d : o = %d\n", i, n, is_close(tmp->index, *dst), (*dst)->index, tmp->num, tmp->order);
int	find_number(t_list **src, t_list **dst)
{
	int		i;
	int		j;
	int		n;
	t_list	*tmp;

	//print_list(*src, "SRC");
	//print_list(*dst, "DST");
	n = 15;
	while (n++)
	{
		i = 0;
		j = 0;
		tmp = (*src)->next;
		if (!(*src)->order && (is_close((*src)->index, *dst) < n || count_larger_than(*src, 0) == 1))
			return (0);
		while (++i)
		{
			if ((!tmp->order && is_close(tmp->index, *dst) < n) || tmp == *src)
				break ;
			tmp = tmp->next;
		}
		tmp = (*src)->prev;
		while (++j < i)
		{
			if ((!tmp->order && is_close(tmp->index, *dst) < n) || tmp == *src)
				break ;
			tmp = tmp->prev;
		}
		if (tmp != *src || i != j)
			break ;
	}
	if (i > j)
		return (j * -1);
	return (i);
}

/* Push number to list B if it is not ordered and is greater than threshold.
Rotate A otherwise. */
void	push_forth(t_list **start_a, t_list **start_b, t_cmd **cmds)
{
	static int	i;
	int 		f;

	//print_list(*start_a, "START_A");
	//print_list(*start_b, "START_B");
	if ((*start_a)->order)
		rotate(start_a, 'a', cmds);
	else if (!*start_b || i++ < 20)
		push_b(start_a, start_b, cmds);
	else
	{
		f = find_number(start_a, start_b);
		//printf("PF: FIND_NUM :: f = %d\n", f);
		//print_list(*start_a, "START_A");
		//print_list(*start_b, "START_B");
		if (f < 0)
			while (f++ < 0)
				rev_rotate(start_a, 'a', cmds);
		else if (f > 0)
			while (f-- > 0)
				rotate(start_a, 'a', cmds);
		push_b(start_a, start_b, cmds);
	}
}

/*else if (is_close((*start_a)->index, *start_b) < 3)
	{
		printf("PF: IS_CLOSE\n");
		while (next_is_closer(start_a, start_b))
			rotate_to_closest(start_a, start_b, cmds);
		push_b(start_a, start_b, cmds);
	} */

/*

void	push_forth(t_list **start_a, t_list **start_b, int threshold,
t_cmd **cmds)
{
	static int	i;

	//print_list(*start_a, "START_A");
	//print_list(*start_b, "START_B");
	if ((*start_a)->order || (*start_a)->index < threshold)
		rotate(start_a, 'a', cmds);
	else if (!*start_b || i++ < 10 || (i >= 10 && is_close((*start_a)->index, *start_b) < 4))
		push_b(start_a, start_b, cmds);
	else
	{
		if (next_is_closer(start_a, start_b, threshold))
		{
			while (next_is_closer(start_a, start_b, threshold))
			{
				swap(start_a, 'a', cmds);
				push_b(start_a, start_b, cmds);
				if (next_is_closer(&((*start_a)->next), start_b, threshold))
				{
					rotate(start_a, 'a', cmds);
					rotate(start_a, 'a', cmds);
				}
			}
		}
		else if (prev_is_closer(start_a, start_b, threshold))
		{
			while (prev_is_closer(start_a, start_b, threshold))
			{
				rev_rotate(start_a, 'a', cmds);
				push_b(start_a, start_b, cmds);
			}
		}
		else
			push_b(start_a, start_b, cmds);
	}
}

void	push_forth(t_list **start_a, t_list **start_b, int threshold,
t_cmd **cmds)
{
	if ((*start_a)->order || (*start_a)->index < threshold)
		rotate(start_a, 'a', cmds);
	else
	{
		if (next_is_closer(start_a, start_b, threshold))
		{
			while (next_is_closer(start_a, start_b, threshold))
			{
				swap(start_a, 'a', cmds);
				push_b(start_a, start_b, cmds);
			}
		}
		else
			push_b(start_a, start_b, cmds);
	}
}
*/
