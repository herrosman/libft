#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;
	
	count= 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	k;
	size_t	words;
	size_t	start;
	
	i= 0;
	k = 0;
	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = (char **)malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			printf("end: %zu\n", i);
			res[k++] = ft_substr(s, start, i - start);
		}
	}
	res[k] = NULL;
	return (res);
}