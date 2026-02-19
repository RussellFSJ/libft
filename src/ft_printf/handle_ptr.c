/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russ1337 <russ1337@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:08:17 by rfoo              #+#    #+#             */
/*   Updated: 2026/02/20 05:23:37 by russ1337         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	handle_ptr(va_list *args)
{
	void			*ptr;
	unsigned long	address;

	ptr = va_arg(*args, void *);
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	address = (unsigned long)ptr;
	return (write(1, "0x", 2) + print_hex(address, 0));
}
