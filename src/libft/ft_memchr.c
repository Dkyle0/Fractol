/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:31:08 by dkyle             #+#    #+#             */
/*   Updated: 2018/11/30 14:31:09 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	bc;

	str = (unsigned char*)s;
	bc = (unsigned char)c;
	while (n--)
	{
		if (*str == bc)
			return (str);
		str++;
	}
	return (NULL);
}
