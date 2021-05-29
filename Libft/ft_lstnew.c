#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*res;

	res = malloc(sizeof(struct s_list));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}
