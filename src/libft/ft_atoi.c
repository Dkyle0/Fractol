/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:39:28 by dkyle             #+#    #+#             */
/*   Updated: 2018/11/28 12:39:30 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	chek_over(long int r, int sign)
{
	if (r < 0 && sign == 1)
		return (-1);
	else if (r < 0 && sign == -1)
		return (0);
	return (1);
}

int			ft_atoi(const char *str)
{
	int			sign;
	long int	r;
	long int	i;

	i = 0;
	sign = 1;
	r = 0;
	while (*str == ' ' || *str == '0' || *str == '\t' || *str == '\n' ||
			*str == '\v' || *str == '\r' || *str == '\f')
		str++;
	if (str[i] == '-')
	{
		sign = sign * (-1);
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
		if (chek_over(r, sign) < 1)
			return (chek_over(r, sign));
	}
	return ((int)r * sign);
}
