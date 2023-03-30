/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:35:48 by lucade-s          #+#    #+#             */
/*   Updated: 2022/09/22 20:05:49 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	length;
	char	*sub;

	length = ft_strlen(s);
	if (start >= length)
		sub = malloc(1);
	else if (len < length - start)
		sub = malloc(len + 1);
	else
		sub = malloc(length - start + 1);
	if (sub == NULL)
		return (NULL);
	i = 0;
	if (start < length)
	{
		while (s[start] && i < len)
		{
			sub[i] = s[start];
			i++;
			start++;
		}
	}
	sub[i] = '\0';
	return (sub);
}
