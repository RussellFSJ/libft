/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russ1337 <russ1337@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:12:02 by rfoo              #+#    #+#             */
/*   Updated: 2026/02/20 05:23:37 by russ1337         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hex(unsigned long n, int uppercase)
{
	const char	*hex;
	char		buffer[17];
	int			i;

	hex = "0123456789abcdef";
	if (uppercase)
		hex = "0123456789ABCDEF";
	i = 16;
	buffer[i] = '\0';
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		buffer[--i] = hex[n % 16];
		n /= 16;
	}
	return (write(1, &buffer[i], 16 - i));
}
