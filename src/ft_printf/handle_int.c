/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russ1337 <russ1337@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:03:39 by rfoo              #+#    #+#             */
/*   Updated: 2026/02/20 05:23:37 by russ1337         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_int(long nbr);

int	handle_int(va_list *args)
{
	int	n;

	n = va_arg(*args, int);
	return (print_int((long)n));
}

static int	print_int(long nbr)
{
	int		bytes;

	bytes = 0;
	if (nbr < 0)
	{
		bytes += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		bytes += print_int(nbr / 10);
	bytes += write(1, &(char){(nbr % 10) + '0'}, 1);
	return (bytes);
}
