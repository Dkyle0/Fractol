/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:35:21 by dkyle             #+#    #+#             */
/*   Updated: 2018/11/27 17:35:23 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	b;
	int		l;

	l = ft_strlen(s);
	str = (char*)s;
	b = (char)c;
	while (l >= 0)
	{
		if (str[l] == c)
			return (str + l);
		l--;
	}
	return (NULL);
}
