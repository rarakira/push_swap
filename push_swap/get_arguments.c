#include "push_swap.h"

/* Check for duplicates in list */
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

/* Create new t_list element */
static t_list	*init_value(char *num)
{
	t_list		*this;
	int			i;

	i = 0;
	if (num[i] == '-' && ft_isdigit(num[i + 1]))
		i++;
	while (num[i] != '\0')
		if (!ft_isdigit(num[i++]))
			return (NULL);
	this = (t_list *)malloc(sizeof(t_list));
	if (!this)
		return (NULL);
	this->next = NULL;
	this->prev = NULL;
	this->top = 0;
	this->order = 0;
	this->index = 0;
	if (ft_atoi(num) < -2147483648 || ft_atoi(num) > 2147483647)
	{
		free(this);
		return (NULL);
	}
	this->num = ft_atoi(num);
	return (this);
}

/* Create a list from the arguments passed to function */
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
			clean_list(start);
			return (NULL);
		}
		current->next->prev = current;
		current = current->next;
	}
	current->next = start;
	start->prev = current;
	return (start);
}
