#include "push_swap.h"

int	checker(t_list **start_a, t_list **start_b, int print_flag, t_cmd **cmds)
{
	char	*cmd;
	int		res;

	cmd = NULL;
	ft_putstr_fd("> ", 1);
	res = get_next_line(0, &cmd);
	while (res > 0)
	{
		res = exec_cmd(cmd, start_a, start_b, cmds);
		if (res == -2)
			break ;
		if (print_flag)
			print_lists(*start_a, *start_b, cmd);
		free(cmd);
		ft_putstr_fd("> ", 1);
		res = get_next_line(0, &cmd);
	}
	free(cmd);
	if (print_flag)
		print_lists(*start_a, *start_b, "Stacks on Finish");
	if (res == -1)
		return (-1);
	if (!*start_b && in_order(*start_a, 'a') && res != -2)
		return (1);
	return (0);
}

static void	print_result(int res)
{
	if (res == 1)
		ft_putendl_fd("\033[1;38;5;42mOK\033[0m", 1);
	else if (res == 0)
		ft_putendl_fd("\033[1;38;5;203mKO\033[0m", 1);
	else if (res == -1)
		ft_putendl_fd("\033[1;38;5;203mOops, something went wrong.\033[0m", 2);
}

int	main(int argc, char **argv)
{
	t_list	*start_a;
	t_list	*start_b;
	t_cmd	*cmds;
	int		print_flag;

	cmds = NULL;
	print_flag = 0;
	start_b = NULL;
	if (argc == 1)
		return (1);
	if (!ft_strncmp("--print", argv[1], ft_strlen("--print")))
	{
		print_flag = 1;
		argc--;
		argv++;
	}
	if (argc == 1)
		return (1);
	start_a = get_arguments(argc, argv);
	if (!start_a)
	{
		ft_putendl_fd("\033[1;38;5;203mError\033[0m", 2);
		return (1);
	}
	if (print_flag)
		print_lists(start_a, start_b, "Stacks on Start");
	print_result(checker(&start_a, &start_b, print_flag, &cmds));
	clean_cmds(cmds);
	clean_list(start_a);
	clean_list(start_b);
	return (0);
}
