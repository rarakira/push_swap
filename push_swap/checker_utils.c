#include "push_swap.h"

static int	exec_rev(char *cmd, t_list **lst_a, t_list **lst_b, t_cmd **cmds)
{
	if (!ft_strncmp("rra", cmd, ft_strlen(cmd)))
		rev_rotate(lst_a, 'a', cmds);
	else if (!ft_strncmp("rrb", cmd, ft_strlen(cmd)))
		rev_rotate(lst_b, 'b', cmds);
	else if (!ft_strncmp("rrr", cmd, ft_strlen(cmd)))
	{
		rev_rotate(lst_a, 'a', cmds);
		rev_rotate(lst_b, 'b', cmds);
	}
	else
	{
		ft_putstr_fd("\033[0;38;5;203mUnknown operation: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd("\033[0m", 2);
		return (-2);
	}
	return (1);
}

static int	exec_rotate(char *cmd, t_list **lst_a, t_list **lst_b, t_cmd **cmds)
{
	if (!ft_strncmp("ra", cmd, ft_strlen(cmd)))
		rotate(lst_a, 'a', cmds);
	else if (!ft_strncmp("rb", cmd, ft_strlen(cmd)))
		rotate(lst_b, 'b', cmds);
	else if (!ft_strncmp("rr", cmd, ft_strlen(cmd)))
	{
		rotate(lst_a, 'a', cmds);
		rotate(lst_b, 'b', cmds);
	}
	else
	{
		ft_putstr_fd("\033[0;38;5;203mUnknown operation: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd("\033[0m", 2);
		return (-2);
	}
	return (1);
}

static int	exec_push(char *cmd, t_list **lst_a, t_list **lst_b, t_cmd **cmds)
{
	if (!ft_strncmp("pa", cmd, ft_strlen(cmd)))
		push(lst_b, lst_a, cmds, 'a');
	else if (!ft_strncmp("pb", cmd, ft_strlen(cmd)))
		push(lst_a, lst_b, cmds, 'b');
	else
	{
		ft_putstr_fd("\033[0;38;5;203mUnknown operation: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd("\033[0m", 2);
		return (-2);
	}
	return (1);
}

static int	exec_swap(char *cmd, t_list **lst_a, t_list **lst_b, t_cmd **cmds)
{
	if (!ft_strncmp("sa", cmd, ft_strlen(cmd)))
		swap(lst_a, 'a', cmds);
	else if (!ft_strncmp("sb", cmd, ft_strlen(cmd)))
		swap(lst_b, 'b', cmds);
	else if (!ft_strncmp("ss", cmd, ft_strlen(cmd)))
	{
		swap(lst_a, 'a', cmds);
		swap(lst_b, 'b', cmds);
	}
	else
	{
		ft_putstr_fd("\033[0;38;5;203mUnknown operation: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd("\033[0m", 2);
		return (-2);
	}
	return (1);
}

int	exec_cmd(char *cmd, t_list **start_a, t_list **start_b, t_cmd **cmds)
{
	int		res;

	if (*cmd == 's')
		res = exec_swap(cmd, start_a, start_b, cmds);
	else if (*cmd == 'p')
		res = exec_push(cmd, start_a, start_b, cmds);
	else if (*cmd == 'r' && cmd[1] == 'r' && cmd[2])
		res = exec_rev(cmd, start_a, start_b, cmds);
	else if (*cmd == 'r')
		res = exec_rotate(cmd, start_a, start_b, cmds);
	else
	{
		ft_putstr_fd("\033[0;38;5;203mUnknown operation: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd("\033[0m", 2);
		return (-2);
	}
	return (res);
}
