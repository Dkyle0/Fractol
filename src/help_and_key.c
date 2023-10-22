/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_and_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 17:59:30 by dkyle             #+#    #+#             */
/*   Updated: 2019/06/30 17:59:32 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		all_keys3(int key, struct s_to_hook *data_hook)
{
	if (key == 123)
	{
		data_hook->move_x -= 25;
		clean_and_start(data_hook);
	}
	if (key == 69)
	{
		data_hook->zoom *= 1.15;
		clean_and_start(data_hook);
	}
	if (key == 18)
	{
		data_hook->f_type = 1;
		clean_and_start(data_hook);
	}
	if (key == 19)
	{
		data_hook->f_type = 2;
		clean_and_start(data_hook);
	}
	return (all_keys4(key, data_hook));
}

int		all_keys2(int key, struct s_to_hook *data_hook)
{
	if (key == 78)
	{
		data_hook->zoom *= 0.85;
		clean_and_start(data_hook);
	}
	if (key == 125)
	{
		data_hook->move_y += 25;
		clean_and_start(data_hook);
	}
	if (key == 126)
	{
		data_hook->move_y -= 25;
		clean_and_start(data_hook);
	}
	if (key == 124)
	{
		data_hook->move_x += 25;
		clean_and_start(data_hook);
	}
	return (all_keys3(key, data_hook));
}

int		all_keys(int key, void *param)
{
	struct s_to_hook	*data_hook;

	data_hook = param;
	if (key == 4)
		draw_help(data_hook);
	if (key == 8)
		mlx_clear_window(data_hook->mlx_ptr, data_hook->win_ptr);
	if (key == 53)
		exit(0);
	if ((key == 45) || (key == 36))
	{
		data_hook->zoom = 1;
		data_hook->move_x = 0.0;
		data_hook->move_y = 0.0;
		data_hook->color.rgb = 0xc42121;
		data_hook->max_it = 100;
		data_hook->gradient = 0;
		data_hook->jx_mouse = 0;
		data_hook->jy_mouse = 0;
		data_hook->build = 0;
		data_hook->ex_color = 0x000000;
		clean_and_start(data_hook);
	}
	return (all_keys2(key, data_hook));
}

void	draw_help2(struct s_to_hook *data_hook)
{
	mlx_string_put(data_hook->mlx_ptr, data_hook->win_ptr, 150, 255,
			0xFFFFFF, " +-: change  max iteration");
	mlx_string_put(data_hook->mlx_ptr, data_hook->win_ptr, 150, 280,
			0xFFFFFF, " < ^ > : Move");
	mlx_string_put(data_hook->mlx_ptr, data_hook->win_ptr, 150, 305,
			0xFFFFFF, " NUM 1 || 2 || 3: change color (r, g, b)");
	mlx_string_put(data_hook->mlx_ptr, data_hook->win_ptr, 150, 330,
			0xFFFFFF, " * : external color");
	mlx_string_put(data_hook->mlx_ptr, data_hook->win_ptr, 150, 355,
			0xFFFFFF, " mouse left : freeze/unfreeze Julia");
	mlx_string_put(data_hook->mlx_ptr, data_hook->win_ptr, 1000, 580,
	0xc42121, "Press N or Enter to start");
}

void	draw_help(struct s_to_hook *data_hook)
{
	mlx_clear_window(data_hook->mlx_ptr, data_hook->win_ptr);
	mlx_string_put(data_hook->mlx_ptr, data_hook->win_ptr, 1000, 80,
	0x215fc4, " You can use key:");
	mlx_string_put(data_hook->mlx_ptr, data_hook->win_ptr, 150, 105,
			0xFFFFFF, " Esc: exit");
	mlx_string_put(data_hook->mlx_ptr, data_hook->win_ptr, 150, 130,
			0xFFFFFF, " C: clear(black window)");
	mlx_string_put(data_hook->mlx_ptr, data_hook->win_ptr, 150, 155,
			0xFFFFFF, " H: help(this window)");
	mlx_string_put(data_hook->mlx_ptr, data_hook->win_ptr, 150, 180,
			0xFFFFFF, " 1-5: change type");
	mlx_string_put(data_hook->mlx_ptr, data_hook->win_ptr, 150, 205,
			0xFFFFFF, " * : fractal color");
	mlx_string_put(data_hook->mlx_ptr, data_hook->win_ptr, 150, 230,
			0xFFFFFF, " +-(NUMPAD) || WHEEL : zoom");
	draw_help2(data_hook);
}
