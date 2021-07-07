#include "push_swap.h"

/* Prints out passed list with custom title */
void	print_list(t_list *start, char *title)
{
	printf("\n-------\nPRINT LIST [%s]\n\n", title);
	while (start)
	{
		//printf("%d -> %d -> %d\n", start->num, start->next->num, start->next->next->num);
		printf("%d (o:%d)\n", start->num, start->order);
		start = start->next;
		//printf("%d is top :: %d\n", start->num, start->top);
		if (start->top)
			break ;
	}
	printf("\n-------\n\n");
}
