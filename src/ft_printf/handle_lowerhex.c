/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_lowerhex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russ1337 <russ1337@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:48:58 by rfoo              #+#    #+#             */
/*   Updated: 2026/02/20 05:23:37 by russ1337         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	handle_lowerhex(va_list *args)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	return (print_hex((unsigned long)n, 0));
}
