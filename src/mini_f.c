/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:42:58 by dkyle             #+#    #+#             */
/*   Updated: 2019/04/17 13:43:00 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	erxit(char *str)
{
	ft_putendl(str);
	exit(0);
}

int		ft_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	free_n(int **res, int a)
{
	while (0 < a)
	{
		free(res[a]);
		a--;
	}
	free(res);
	res = NULL;
}

void	clean_and_start(struct s_to_hook *data_hook)
{
	mlx_clear_window(data_hook->mlx_ptr, data_hook->win_ptr);
	general(data_hook);
}

void	color_mixer(struct s_to_hook *data_hook)
{
	if (data_hook->gradient == 4)
	{
		if (data_hook->color.c[0] < 255)
			data_hook->color.c[0]++;
		else
			data_hook->color.c[0] = 0;
	}
	if (data_hook->gradient == 5)
	{
		if (data_hook->color.c[1] < 255)
			data_hook->color.c[1]++;
		else
			data_hook->color.c[1] = 0;
	}
	if (data_hook->gradient == 6)
	{
		if (data_hook->color.c[2] < 255)
			data_hook->color.c[2]++;
		else
			data_hook->color.c[2] = 0;
	}
}
