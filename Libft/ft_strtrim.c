#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	lens;

	if (s1 == NULL)
		return (NULL);
	lens = ft_strlen(s1);
	i = 0;
	j = 0;
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	while (ft_strchr(set, s1[lens - 1]) && lens > i)
		lens--;
	res = (char *)malloc(sizeof(char) * lens - i + 1);
	if (res == NULL)
		return (NULL);
	while (i < lens)
	{
		res[j] = s1[i];
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}
