#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	void			*mem;

	i = 0;
	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > (size_t)(-1)/size)
		return (NULL);
	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, nmemb * size);
	return (mem);
}
