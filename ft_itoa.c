/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:05:06 by rfoo              #+#    #+#             */
/*   Updated: 2025/12/01 21:33:04 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	strlen;
	char	*str;
	int		sign;
	size_t	i;
	int		div;

	if (n == 0)
		return ("0");
	strlen = 0;
	sign = 1;
	if (n < 0)
	{
		strlen++;
		sign = -1;
		n = -n;
	}
	while (n / div > 0)
	{
		strlen++;
		div *= 10;
	}
	str = malloc(strlen + 1);
	if (!str)
		return (NULL);
	if (sign < 0)
	{
		str[0] = '-';
		i++;
	}
	while (i < strlen)
	{
		str[strlen - 1 - i] = n % div + '0';
		div /= 10;
		i++;
	}
	str[strlen] = '\0';
	return (str);
}
