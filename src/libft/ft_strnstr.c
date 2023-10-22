/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:23:37 by dkyle             #+#    #+#             */
/*   Updated: 2018/11/28 12:23:39 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t a;
	size_t b;

	a = 0;
	if ((haystack[0] == '\0' && needle[0] == '\0') || needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[a] != '\0' && a < len)
	{
		if (haystack[a] == needle[0])
		{
			b = 1;
			while (needle[b] != '\0' && haystack[a + b] == needle[b]
				&& (a + b < len))
				++b;
			if (needle[b] == '\0')
				return ((char*)&haystack[a]);
		}
		a++;
	}
	return (NULL);
}
