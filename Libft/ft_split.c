#include "libft.h"

static char	**mem_clean(char **res)
{
	unsigned int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static int 	quant_str(char const *s, char sepr)
{
	unsigned int	i;
	unsigned int	keychar;

	if (!s[0])
		return (0);
	i = 0;
	keychar = 0;
	while (s[i])
	{
		while (s[i] == sepr)
			i++;
		if (i > 0 && s[i] && s[i - 1] == sepr)
			keychar++;
		if (s[i])
			i++;
	}
	if (s[0] != sepr)
		keychar++;
	return (keychar);
}

static int 	len_str(char const *s, unsigned int *beg, char sepr)
{
	int	len;

	len = 0;
	while (s[*beg])
	{
		while (s[*beg] == sepr)
			(*beg)++;
		len++;
		while (s[*beg] != sepr)
		{
			(*beg)++;
			if (s[*beg] == sepr || s[*beg] == '\0')
				return (len);
			len++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char			**res;
	unsigned int	i;
	unsigned int	lens;
	unsigned int	qs;
	unsigned int	beg;

	if (!s)
		return (NULL);
	i = 0;
	beg = 0;
	qs = quant_str(s, c);
	res = (char **)malloc(sizeof(char *) * (qs + 1));
	if (!res)
		return (NULL);
	while (i < qs)
	{
		lens = len_str(s, &beg, c);
		res[i] = (char *)malloc(sizeof(char) * (lens + 1));
		if (!res[i])
			return (mem_clean(res));
		ft_strlcpy(res[i], &s[beg - lens], lens + 1);
		i++;
	}
	res[i] = 0;
	return (res);
}
