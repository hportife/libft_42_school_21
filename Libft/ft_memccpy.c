#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dstt;
	char	*srcc;

	i = 0;
	dstt = (char *)dst;
	srcc = (char *)src;
	while (n--)
	{
		dstt[i] = srcc[i];
		if ((unsigned char)srcc[i] == (unsigned char)c)
			return ((char *)dst + i + 1);
		i++;
	}
	return (NULL);
}
