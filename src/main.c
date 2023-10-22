/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:28:47 by dkyle             #+#    #+#             */
/*   Updated: 2019/03/06 16:28:49 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_init(struct s_to_hook *data_hook, float type)
{
	data_hook->f_type = type;
	data_hook->height = 2200;
	data_hook->weight = 1100;
	data_hook->bpp = 32;
	data_hook->size_line = 4 * data_hook->height;
	data_hook->endian = 0;
	data_hook->j_mouse = 1;
	data_hook->mlx_ptr = mlx_init();
	data_hook->win_ptr = mlx_new_window(data_hook->mlx_ptr,
	data_hook->height, data_hook->weight, "fractol");
	data_hook->img_ptr = mlx_new_image(data_hook->mlx_ptr,
	data_hook->height, data_hook->weight);
	data_hook->addr_ptr = mlx_get_data_addr(data_hook->img_ptr,
	&(data_hook->bpp), &(data_hook->size_line), &(data_hook->endian));
}

void	preload(struct s_to_hook *data_hook)
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

void	mlx_start(float type)
{
	start_init(&data_hook, type);
	if (!(data_hook.imap = (int *)malloc(sizeof(int) *
		(data_hook.height * data_hook.weight))))
		erxit("new map error");
	build_all(&data_hook);
	preload(&data_hook);
	draw_help(&data_hook);
	mlx_hook(data_hook.win_ptr, 2, 0, all_keys, &data_hook);
	mlx_hook(data_hook.win_ptr, 4, 0, mouse_hook, &data_hook);
	mlx_hook(data_hook.win_ptr, 6, 0, mouse_move, &data_hook);
	mlx_hook(data_hook.win_ptr, 17, 0, ft_close, &data_hook);
	mlx_loop(data_hook.mlx_ptr);
	free(data_hook.imap);
	clFinish(data_hook.queue);
	clReleaseKernel(data_hook.kernel);
	clReleaseCommandQueue(data_hook.queue);
	clReleaseProgram(data_hook.program);
	clReleaseContext(data_hook.context);
}

void	start_move(char *argv)
{
	if (ft_strcmp(argv, "julia") == 0 || ft_strcmp(argv, "j") == 0)
		mlx_start(1);
	else if (ft_strcmp(argv, "mandelbrot") == 0 || ft_strcmp(argv, "m") == 0)
		mlx_start(2);
	else if (ft_strcmp(argv, "something") == 0 || ft_strcmp(argv, "s") == 0)
		mlx_start(3);
	else if (ft_strcmp(argv, "burningship") == 0 || ft_strcmp(argv, "bs") == 0)
		mlx_start(4);
	else if (ft_strcmp(argv, "tricorn") == 0 | ft_strcmp(argv, "t") == 0)
		mlx_start(5);
	else
		ft_putendl("usage: ./fractol j \n m \n s \n bs \n t");
}

int		main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putendl("usage: ./fractol j \n m \n s \n bs \n t");
		return (-1);
	}
	if (argc == 2)
		start_move(argv[1]);
	exit(0);
	return (0);
}
