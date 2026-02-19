/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russ1337 <russ1337@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:19:30 by rfoo              #+#    #+#             */
/*   Updated: 2026/02/20 05:23:37 by russ1337         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_uint(unsigned long n);

int	handle_uint(va_list *args)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	return (print_uint((unsigned long)n));
}

static int	print_uint(unsigned long nbr)
{
	int	bytes;

	bytes = 0;
	if (nbr >= 10)
		bytes += print_uint(nbr / 10);
	bytes += write(1, &(char){(nbr % 10) + '0'}, 1);
	return (bytes);
}
