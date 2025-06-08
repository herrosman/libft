#include "libft.h"

// Helper: Check if character c is in set
static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	len;
	size_t	s;
	size_t	e;
	
	if (!s1 || !set)
		return (NULL);

	s = 0;
	while (s1[s] && is_in_set(s1[s], set))
		s++;
	e = ft_strlen(s1);
	while (e > s && is_in_set(s1[e - 1], set))
		e--;
	len = e - s;

	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	len = ft_strlcpy(res, s1 + s, len + 1);
	return (res);
}