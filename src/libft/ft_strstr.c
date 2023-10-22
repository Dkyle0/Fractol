/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:10:46 by dkyle             #+#    #+#             */
/*   Updated: 2018/11/28 12:10:50 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int a;
	int b;

	a = 0;
	if ((haystack[0] == '\0' && needle[0] == '\0') || needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[a])
	{
		if (haystack[a] == needle[0])
		{
			b = 1;
			while (needle[b] != '\0' && haystack[a + b] == needle[b])
				++b;
			if (needle[b] == '\0')
				return ((char*)&haystack[a]);
		}
		a++;
	}
	return (NULL);
}
