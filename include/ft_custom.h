/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 07:42:47 by pguillie          #+#    #+#             */
/*   Updated: 2019/10/06 17:10:40 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUSTOM_H
# define FT_CUSTOM_H

int read_line(int fd, char **line);

char *absolute_path(const char *path, char *resolved_path);

#endif /* FT_CUSTOM_H */
