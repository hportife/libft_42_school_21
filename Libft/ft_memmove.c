#include "libft.h"

void	*ft_memmove (void *dst, const void *src, size_t len)
{
	unsigned char		*dstt;
	const unsigned char	*srcc;
	size_t				i;

	dstt = (unsigned char *)dst;
	srcc = (const unsigned char *)src;
	i = 0;
	if (dstt > srcc)
	{
		while (len > 0)
		{
			dstt[i + len - 1] = srcc[i + len - 1];
			len--;
		}
	}
	if (dstt < srcc)
	{
		while (len > i)
		{
			dstt[i] = srcc[i];
			i++;
		}
	}
	return (dst);
}
