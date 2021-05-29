#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	k;

	k = 0;
	while (str[k])
		k++;
	return (k);
}
