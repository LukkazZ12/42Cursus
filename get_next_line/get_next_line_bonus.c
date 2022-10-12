/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:18:47 by lucade-s          #+#    #+#             */
/*   Updated: 2022/10/05 23:59:19 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_nl(int fd, int *count, char **st_str, char *res)
{
	while (!(ft_strchr(*st_str, '\n')))
	{
		*count = read(fd, *st_str, BUFFER_SIZE);
		if (*count <= 0 || !(*st_str)[0])
		{
			if (*count < 0 || !(*st_str)[0])
			{
				free(res);
				res = NULL;
			}
			free(*st_str);
			*st_str = NULL;
			return (res);
		}
		(*st_str)[*count] = '\0';
		res = ft_strjoin(res, *st_str);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	int			count;
	char		*res;
	static char	*st_str[1024];

	count = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!st_str[fd])
		st_str[fd] = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	res = (char *)ft_calloc(1, sizeof(char));
	if (!res || !st_str[fd])
		return (NULL);
	res = ft_strjoin(res, st_str[fd]);
	res = read_nl(fd, &count, &st_str[fd], res);
	if (count <= 0 || !st_str[fd][0])
		return (res);
	res[ft_strlen(res) - ft_strlen(ft_strchr(res, '\n') + 1)] = '\0';
	if (*(ft_strchr(st_str[fd], '\n') + 1) == '\0')
	{
		free(st_str[fd]);
		st_str[fd] = NULL;
	}
	else
		ft_strcpy(st_str[fd], ft_strchr(st_str[fd], '\n') + 1);
	return (res);
}
