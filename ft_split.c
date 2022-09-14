/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:59:15 by coder             #+#    #+#             */
/*   Updated: 2022/09/14 23:01:04 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	l;
	unsigned int	m;
	size_t			length;
	char			**str_substr;

	if (*s == '\0')
	{
		str_substr = malloc(sizeof(char *));
		str_substr[0] = NULL;
		return (str_substr);
	}
	length = ft_strlen(s);
	i = 0;
	j = 0;
	while (s != NULL && s[j])
	{
		if (s[j] == c)
		{
			while (s[j] == c)
				j++;
			i++;
		}
		else
			j++;
	}
	if (s[0] == c && s[length - 1] == c && i != 0)
		i--;
	if (s[0] != c && s[length - 1] != c && i != length && s != NULL)
		i++;
	str_substr = malloc((i + 1) * sizeof(char *));
	if (str_substr == NULL)
		return (NULL);
	j = 0;
	l = 0;
	while (s != NULL && s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		if (s[j] != '\0')
		{
			k = j;
			while (s[k] != c && s[k] != '\0')
				k++;
			str_substr[l] = malloc((k - j + 1) * sizeof(char));
			if (str_substr[l] == NULL)
				return (NULL);
			m = j;
			while (m < k)
			{
				str_substr[l][m - j] = s[m];
				m++;
			}
			str_substr[l][m - j] = '\0';
			l++;
			j = k;
		}
	}
	str_substr[l] = NULL;
	return (str_substr);
}
