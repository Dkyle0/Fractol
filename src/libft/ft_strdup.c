/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:51:16 by dkyle             #+#    #+#             */
/*   Updated: 2018/11/30 15:51:18 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	i = 0;
	while (s1[size])
		size++;
	new = (char*)malloc(sizeof(new) * (size + 1));
	if (new == NULL)
		return (NULL);
	while (i < size)
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
