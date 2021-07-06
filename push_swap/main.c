#include "push_swap.h"

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
		if (!start)
			break ;
	}
}

//print_list(start_a, "MAIN");
int	main(int argc, char **argv)
{
	int		parts;
	int		step;
	t_list	*start_a;

	if (argc == 1)
		return (1);
	start_a = get_arguments(argc, argv);
	if (!start_a)
	{
		ft_putendl_fd("Error", 1);
		return (1);
	}
	step = count_parts(start_a, &parts);
	if (!in_order(start_a))
	{
		mark_ordered(start_a);
		push_swap(&start_a, step, parts);
	}
	clean_all(start_a);
	return (0);
}
