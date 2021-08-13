#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*start_a;
	t_cmd	*cmds;

	cmds = NULL;
	if (argc == 1)
		return (1);
	start_a = get_arguments(argc, argv);
	if (!start_a)
	{
		ft_putendl_fd("\033[1;38;5;203mError\033[0m", 2);
		return (1);
	}
	if (!in_order(start_a, 'a'))
	{
		mark_ordered(start_a);
		push_swap(&start_a, count_elements(start_a), find_max(start_a), &cmds);
	}
	print_cmds(cmds);
	//print_lists(start_a, NULL, "Stacks on Finish");
	clean_list(start_a);
	clean_cmds(cmds);
	return (0);
}
