/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:41:10 by dkyle             #+#    #+#             */
/*   Updated: 2018/11/30 18:41:12 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*re;

	re = (char*)malloc(len + 1);
	if (!(s) || !(re))
		return (NULL);
	ft_strncpy(re, s + start, len);
	re[len] = '\0';
	return (re);
}
