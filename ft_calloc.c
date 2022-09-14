/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:01:46 by coder             #+#    #+#             */
/*   Updated: 2022/09/14 22:05:05 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*t;

	if (nmemb == 0 || size == 0 || nmemb >= 2147483647 / size)
		return (NULL);
	i = nmemb * size;
	t = malloc(i);
	ft_bzero(t, i);
	return (t);
}
