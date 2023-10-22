/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 12:26:09 by dkyle             #+#    #+#             */
/*   Updated: 2019/06/29 12:26:12 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int key, int x, int y, struct s_to_hook *data_hook)
{
	if (key == 5)
	{
		data_hook->zoom *= 0.85;
		data_hook->move_x *= 0.85;
		data_hook->move_y *= 0.85;
	}
	else if (key == 4)
	{
		data_hook->zoom *= 1.15;
		data_hook->move_x += ((data_hook->height / 2 - x)
		/ 4 * data_hook->zoom);
		data_hook->move_y += ((data_hook->weight / 2 - y)
		/ 4 * data_hook->zoom);
	}
	x = 1;
	y = 1;
	if (key == 1 && data_hook->f_type == 1 && data_hook->j_mouse == 1)
		data_hook->j_mouse = 0;
	else if (key == 1 && data_hook->f_type == 1 && data_hook->j_mouse == 0)
		data_hook->j_mouse = 1;
	clean_and_start(data_hook);
	return (0);
}

int		mouse_move(int x, int y, struct s_to_hook *data_hook)
{
	if (data_hook->f_type == 1 && data_hook->j_mouse == 1)
	{
		data_hook->jx_mouse = ((double)x - 500) / data_hook->weight;
		data_hook->jy_mouse = ((double)y - 500) / data_hook->height;
		clean_and_start(data_hook);
	}
	return (0);
}
