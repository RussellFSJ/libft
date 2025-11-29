#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	void			*mem;

	i = 0;
	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, nmemb * size);
	return (mem);
}
