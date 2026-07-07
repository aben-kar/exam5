#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	*cpy;
	int		count;

	cpy = begin_list;
	count = 0;
	while (cpy)
	{
		cpy = cpy->next;
		count++;
	}
	return (count);
}
