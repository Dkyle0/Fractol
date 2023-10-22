/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:24:15 by dkyle             #+#    #+#             */
/*   Updated: 2018/11/30 17:24:16 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	char			*str;
	unsigned int	i;
	unsigned int	size;

	size = 0;
	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	str = (char*)s;
	while (s[size])
		size++;
	if (!(fresh = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		fresh[i] = f(i, str[i]);
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
