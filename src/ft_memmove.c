/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 08:46:11 by pguillie          #+#    #+#             */
/*   Updated: 2019/07/30 18:40:14 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d, *s;
	size_t i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest < src) {
		i = 0;
		while (i < n) {
			d[i] = s[i];
			i++;
		}
	} else {
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}
