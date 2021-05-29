#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dstt;
	char	*srcc;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	dstt = (char *)dst;
	srcc = (char *)src;
	while (i < n)
	{
		dstt[i] = srcc[i];
		i++;
	}
	return (dst);
}
