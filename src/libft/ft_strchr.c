/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:15:29 by dkyle             #+#    #+#             */
/*   Updated: 2018/11/27 17:15:30 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	b;

	str = (char*)s;
	b = (char)c;
	while (*str && (*str != b))
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}
