/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:28:20 by dkyle             #+#    #+#             */
/*   Updated: 2018/11/30 16:28:21 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	char	*str;
	int		i;
	int		size;

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
		fresh[i] = f(str[i]);
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
