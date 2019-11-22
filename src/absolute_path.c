/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absolute_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:12:50 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/22 08:32:52 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#include "libft.h"

static int resolve_path(const char *path, char *res_path, size_t *i)
{
	if (*path == '/')
		return 1;
	if (*path == '.') {
		if (path[1] == '\0' || path[1] == '/')
			return 1;
		if (path[1] == '.' && (path[2] == '\0' || path[2] == '/')) {
			if (*i == 1)
				return 2;
			while (res_path[--(*i) - 1] != '/')
				;
			return 2;
		}
	}
	return 0;
}

static size_t prefix(const char **path, char *res_path)
{
	size_t len;
	if (**path != '/') {
		if (getcwd(res_path, PATH_MAX - 2) == NULL)
			return 0;
		len = ft_strlen(res_path);
		if (res_path[len - 1] != '/')
			res_path[len++] = '/';
	} else {
		res_path[0] = '/';
		(*path)++;
		len = 1;
	}
	return len;
}

char *absolute_path(const char *path, char *resolved_path)
{
	size_t i, j;

	i = prefix(&path, resolved_path);
	if (i == 0)
		return NULL;
	while (*path != '\0') {
		j = resolve_path(path, resolved_path, &i);
		if (j == 0) {
			while (path[j] != '\0' && path[j] != '/') {
				if (i > PATH_MAX - 3)
					return NULL;
				resolved_path[i++] = path[j++];
			}
			resolved_path[i] = '\0';
			if (access(resolved_path, F_OK) != 0)
				return NULL;
			resolved_path[i++] = '/';
		}
		path += j;
	}
	resolved_path[(i > 1) ? i - 1 : i] = '\0';
	return resolved_path;
}
