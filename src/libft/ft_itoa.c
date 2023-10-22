/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:57:53 by dkyle             #+#    #+#             */
/*   Updated: 2018/12/03 11:57:56 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_int_char(long int n, int z)
{
	int	l;

	l = 0;
	if (z < 0)
		l++;
	if (n == 0)
		l++;
	while (n > 0)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

static char	*magik_work(long int n, int z, int l, char *s)
{
	int sign_mem;

	sign_mem = 0;
	if (z < 0)
	{
		sign_mem++;
		s[0] = '-';
		l--;
	}
	while (l >= 0)
	{
		if (n >= 10)
		{
			s[l + sign_mem] = n % 10 + '0';
			n = n / 10;
			l--;
		}
		else if (n < 10)
		{
			s[l + sign_mem] = n % 10 + '0';
			l--;
		}
	}
	return (s);
}

char		*ft_itoa(int n)
{
	int			z;
	int			l;
	char		*s;
	long int	f;

	z = 1;
	f = n;
	if (f < 0)
	{
		z = -1;
		f = f * (-1);
	}
	l = size_int_char(f, z);
	s = (char*)malloc(sizeof(char) * (l + 1));
	if (!(s))
		return (NULL);
	s[l] = '\0';
	l--;
	s = magik_work(f, z, l, s);
	return (s);
}
