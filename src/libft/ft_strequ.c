/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:58:13 by dkyle             #+#    #+#             */
/*   Updated: 2018/11/29 17:58:15 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (s1[i] && s2[i])
		{
			if (s1[i] == s2[i])
				i++;
			else
				return (0);
		}
		if ((s1[i] == '\0') && (s2[i] == '\0'))
			return (1);
		else
			return (0);
	}
	if ((s1 == NULL && s2 != NULL) || (s1 != NULL && s2 == NULL))
		return (0);
	return (1);
}
