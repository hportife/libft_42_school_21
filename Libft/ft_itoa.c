#include "libft.h"

static	int	ft_nbrlen(int nbr)
{
	int	i;

	if (nbr == -2147483648)
	{
		i = 11;
		return (i);
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		i = 2;
	}
	else
		i = 1;
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static	void	keks(char **res, size_t *lens, int n)
{
	*lens = ft_nbrlen(n);
	*res = (char *)malloc(sizeof(char) * (*lens) + 1);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	lens;

	keks(&res, &lens, n);
	if (res == NULL)
		return (NULL);
	res[lens--] = '\0';
	if (n == -2147483648)
	{
		res[lens--] = '8';
		n /= 10;
	}
	if (n < 0)
	{
		n = -n;
		res[0] = '-';
	}
	if (n == 0)
		res[lens] = '0';
	while (n)
	{
		res[lens--] = 48 + (n % 10);
		n = n / 10;
	}
	return (res);
}
