#include "libft.h"

char	*ft_strmapi(char const *a, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*str;

	if (!a || !f)
        return (NULL);
	i = 0;
	len = ft_strlen(a);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = f(i, a[i]);
		i++;
	}
	str[len] = '\0';
	return (str);
}
