/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:55:30 by dkyle             #+#    #+#             */
/*   Updated: 2018/11/27 16:55:32 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	min(size_t a, size_t size)
{
	if (a < size)
		return (a);
	else
		return (size);
	return (0);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t a;
	size_t b;
	size_t c;

	a = ft_strlen(dst);
	b = ft_strlen(src);
	c = min(a, size) + b;
	if (!(size <= a))
	{
		dst += a;
		size -= a;
		while (*src && size > 1)
		{
			*dst++ = *src++;
			size--;
		}
		*dst = '\0';
	}
	return (c);
}
