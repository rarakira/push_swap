#include "push_swap.h"

void	order_list(t_list **list, char list_name)
{
	if (closer_to_start(find_min(*list), *list))
		while (!in_order(*list))
			rotate(list, list_name);
	else
		while (!in_order(*list))
			rev_rotate(list, list_name);
}

void	print_list(t_list *start, int min_n, int max_n)
{
	printf("\n-------\nPRINT LIST %d, max is %d\n\n", min_n, max_n);
	while (start)
	{
		//printf("%d -> %d -> %d\n", start->num, start->next->num, start->next->next->num);
		printf("%d\n", start->num);
		start = start->next;
		//printf("%d is top :: %d\n", start->num, start->top);
		if (start->top)
			break;
	}
	printf("\n-------\n\n");
	//if (start)
	//{
	//	for (int i = 0; i < 10; i++)
	//	{
	//		printf("[%d] num = %d, top : %d\n", i, start->num, start->top);
	//		start = start->prev;
	//	}
	//}
	//printf("\n-------\n\n");
}

void	print_back(t_list *start, int min_n, int max_n)
{
	printf("\n-------\nPRINT BACKWARDS %d, max is %d\n\n", min_n, max_n);
	while (start)
	{
		start = start->prev;
		printf("%d\n", start->num);
		if (start->top)
			break ;
	}
	printf("\n-------\n\n");
	//if (start)
	//{
	//	for (int i = 0; i < 10; i++)
	//	{
	//		printf("[%d] num = %d, top : %d\n", i, start->num, start->top);
	//		start = start->prev;
	//	}
	//}
	//printf("\n-------\n\n");
}

void	clean_all(t_list *start)
{
	t_list	*current;

	if (start->prev)
	{
		current = start->prev;
		current->next = NULL;
	}
	while (start)
	{

		current = start;
		start = start->next;
		free(current);
		if (current == current->next || current->top)
			break ;
	}
}

int	push_swap(t_list **start_a, int min_n)
{
	static t_list	*start_b;
	//print_list(*start_a, min_n, 123);
	//print_list(start_b, min_n, 567);
	if (!start_b && in_order(*start_a)) // all in order
		return (0);
	if ((*start_a)->num < (*start_a)->next->num || \
		(((*start_a)->num > (*start_a)->next->num) && !(*start_a)->next->next))
		rotate(start_a, 'a');
	else
		push_b(start_a, &start_b);
	//if ((*start_a)->num == min_n && !in_order(*start_a))
	//	push_swap(start_a, min_n);
	if (start_b && in_order(*start_a))
	{
		order_list(&start_b, 'b');
		while (start_b)
		{
			while (start_b && (*start_a)->num > start_b->num)
				push_a(&start_b, start_a);
			rotate(start_a, 'a');
			while (start_b && (*start_a)->num == min_n
				&& is_last(*start_a, start_b->num))
			{
				push_a(&start_b, start_a);
				rotate(start_a, 'a');
			}
		}
		order_list(start_a, 'a');
	}
	return (push_swap(start_a, min_n));
}

int	main(int argc, char **argv)
{
	int		min_n;
	int		max_n;
	int		mid_n;
	int		res;
	t_list	*start_a;

	start_a = get_arguments(argc, argv, &min_n, &max_n);
	if (!start_a)
	{
		ft_putendl_fd("Error", 1);
		return (1);
	}
	//print_list(start_a, min_n, 1);
	mid_n = (min_n + max_n) / 2;
	if (!in_order(start_a))
		res = push_swap(&start_a, min_n);
	//print_list(start_a, min_n, 2);
	clean_all(start_a);
	return (0);
}
