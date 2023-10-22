/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:12:23 by dkyle             #+#    #+#             */
/*   Updated: 2018/11/30 18:12:25 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*re;
	int		ls1;
	int		ls2;

	if (!s1 && !s2)
		return (NULL);
	if (s1 != NULL && s2 != NULL)
	{
		ls1 = ft_strlen(s1);
		ls2 = ft_strlen(s2);
		re = (char *)malloc(ls1 + ls2 + 1);
		if (re == NULL)
			return (NULL);
		ft_strcpy(re, s1);
		ft_strcpy(re + ls1, s2);
		re[ls1 + ls2] = '\0';
		return (re);
	}
	return (NULL);
}
