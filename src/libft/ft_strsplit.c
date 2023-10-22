/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:10:53 by dkyle             #+#    #+#             */
/*   Updated: 2018/12/03 12:10:54 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_n(char const *s, char c)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (((s[i] != c) && s[i + 1] == c) ||
			((s[i] != c) && s[i + 1] == '\0'))
			n++;
		i++;
	}
	return (n);
}

static void		free_m(char **res, int a)
{
	int ia;

	ia = 0;
	while (ia < a)
	{
		free(res[ia]);
		ia++;
	}
	free(res);
	res = NULL;
}

static int		*rec(char *r, char const *s, int b, int i)
{
	while (b >= 0)
	{
		r[b] = s[i];
		b--;
		i--;
	}
	return (0);
}

static char		**spliter(char const *s, char c, char **res)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	a = -1;
	b = 0;
	while (s[i])
	{
		if (s[i] != c)
			b++;
		if (((s[i] != c) && s[i + 1] == c) || ((s[i] != c) && s[i + 1] == '\0'))
		{
			a++;
			if (!(res[a] = (char*)malloc(sizeof(char*) * (b + 1))))
				return (NULL);
			res[a][b] = '\0';
			rec(res[a], s, b - 1, i);
			b = 0;
			if (a > 1 && !(res[a]))
				free_m(res, a);
		}
		i++;
	}
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;

	if (!(s))
		return (NULL);
	res = (char**)malloc(sizeof(char*) * (word_n(s, c) + 1));
	if (!(res))
		return (NULL);
	res = spliter(s, c, res);
	res[(word_n(s, c))] = NULL;
	return (res);
}
