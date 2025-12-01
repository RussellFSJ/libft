#include "libft.h"

static int	count_words(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*start;
	char	*end;
	size_t	i;

	if (!s)
		return (NULL);
	arr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return(NULL);
	start = s;
	end = ft_strchr(s, c);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if(*s)
		{
			start = s;
			end = ft_strchr(s, c);
			if (!end)
				end = s + ft_strlen(s);
			arr[i] = ft_substr(start, 0, end - start);
			s = end;
			i++;
		}
	}
	arr[i] = NULL;
	return (arr);
}

static int	count_words(char const *s, char c)
{
	size_t	count;
	int		new_word;
	
	count = 0;
	new_word = 1;
	while (*s)
	{
		if (*s != c && new_word)
		{
			new_word = 0;
			count++;
		}
		else if (*s == c)
			new_word = 1;
		s++;
	}
	return (count);
}
