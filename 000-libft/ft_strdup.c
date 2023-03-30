/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:34:52 by lucade-s          #+#    #+#             */
/*   Updated: 2022/09/22 17:35:20 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	length;
	char	*c;

	length = ft_strlen(s);
	c = malloc(length + 1);
	if (c == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		c[i] = s[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
