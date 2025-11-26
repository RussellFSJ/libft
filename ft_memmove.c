/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:15:17 by rfoo              #+#    #+#             */
/*   Updated: 2025/11/26 19:30:05 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;
	unsigned char	temp[1024];

	i = 0;
	p1 = (unsigned char *)src;
	p2 = (unsigned char *)dest;
	while(i < n)
	{
		temp[i] = p1[i];
		i++;
	}
	temp[i] = 0;
	i = 0;
	while(temp[i])
	{
		p2[i] = temp[i];
		i++;
	}
	return (dest);
}
