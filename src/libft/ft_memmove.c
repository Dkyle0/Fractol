/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:17:23 by dkyle             #+#    #+#             */
/*   Updated: 2018/11/30 14:17:25 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	more25(size_t len, unsigned char *d, unsigned char *s)
{
	while (len--)
	{
		*--d = *--s;
	}
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (s > d)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		d += len;
		s += len;
		more25(len, d, s);
	}
	return (dst);
}
