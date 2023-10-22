/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:54:53 by dkyle             #+#    #+#             */
/*   Updated: 2018/12/03 11:55:00 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_char(char const *str, int i)
{
	while (str[i])
	{
		if (str[i] > 32 && str[i] < 127)
			return (1);
		i++;
	}
	return (0);
}

static int		delend(char const *str, int s)
{
	if (str[s] == '\0' && s > 0)
		s--;
	while ((str[s] == ' ' || str[s] == '\n' || str[s] == '\t') && s >= 0)
		s--;
	if (s < 0)
		s = 0;
	return (s);
}

static int		miss_space(char const *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char	*fresh;
	int		i;
	int		fi;
	int		size;

	fi = 0;
	if (!s)
		return (NULL);
	i = miss_space(s);
	size = delend(s, (int)ft_strlen(s)) - miss_space(s) + 1;
	if (size < 0)
		size = 0;
	fresh = (char*)malloc(sizeof(char) * (size + 1));
	if (!(fresh))
		return (NULL);
	while (check_char(s, i))
	{
		fresh[fi] = s[i];
		i++;
		fi++;
	}
	fresh[fi] = '\0';
	return (fresh);
}
