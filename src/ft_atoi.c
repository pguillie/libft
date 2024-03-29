/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 08:45:44 by pguillie          #+#    #+#             */
/*   Updated: 2019/09/12 07:19:52 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

int ft_atoi(const char *nptr)
{
	int n;
	size_t i;

	while (ft_isspace(*nptr))
		nptr++;
	n = 0;
	i = 0;
	if (nptr[0] == '-' || nptr[0] == '+')
		i++;
	if (nptr[0] == '-') {
		while (ft_isdigit(nptr[i]))
			n = n * 10 - nptr[i++] + '0';
	} else {
		while (ft_isdigit(nptr[i]))
			n = n * 10 + nptr[i++] - '0';
	}
	return (n);
}
