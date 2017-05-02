/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:06:30 by pguillie          #+#    #+#             */
/*   Updated: 2017/05/02 15:38:37 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_error(char *msg, ...)
{
	va_list	ap;

	if (!msg)
		return (1);
	va_start(ap, msg);
	ft_putstr_fd(msg, 2);
	while ((msg = va_arg(ap, char*)))
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(msg, 2);
	}
	ft_putchar_fd('\n', 2);
	return (1);
}
