/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russ1337 <russ1337@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:15:17 by rfoo              #+#    #+#             */
/*   Updated: 2026/02/19 07:02:26 by russ1337         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*p1;
	const unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *)dest;
	p2 = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		if (p1 < p2)
			p1[i] = p2[i];
		else
			p1[n - 1 - i] = p2[n - 1 - i];
		i++;
	}
	return (dest);
}
