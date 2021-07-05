#include "push_swap.h"

static int	check_dup(int n, t_list *start)
{
	while (start->next)
	{
		if (n != start->num)
			start = start->next;
		else
			return (1);
	}
	return (0);
}

t_list	*init_value(char	*num)
{
	t_list		*this;
	int			i;

	i = 0;
	while (num[i] != '\0')
		if (ft_isalpha(num[i++]))
			return (NULL);
	this = (t_list *)malloc(sizeof(t_list));
	if (!this)
		return (NULL);
	this->next = NULL;
	this->prev = NULL;
	this->top = 0;
	this->order = 0;
	this->num = ft_atoi(num);
	return (this);
}

t_list	*get_arguments(int argc, char **argv)
{
	t_list			*start;
	t_list			*current;
	unsigned int	i;

	i = 1;
	start = init_value(argv[i++]);
	if (!start)
		return (NULL);
	start->top = 1;
	current = start;
	while (i < (unsigned)argc)
	{
		current->next = init_value(argv[i++]);
		if (!current->next || check_dup(current->next->num, start))
		{
			clean_all(start);
			return (NULL);
		}
		current->next->prev = current;
		current = current->next;
	}
	current->next = start;
	start->prev = current;
	return (start);
}
