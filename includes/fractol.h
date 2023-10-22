/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:27:50 by dkyle             #+#    #+#             */
/*   Updated: 2019/03/07 12:27:55 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <OpenCL/opencl.h>
# include "../src/libft/libft.h"
# include "../minilibx/mlx.h"

union					u_color
{
	unsigned int		rgb;
	unsigned char		c[4];
}						color;

struct					s_to_hook
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	void				*addr_ptr;
	int					size_line;
	int					endian;
	int					bpp;
	int					height;
	int					weight;
	int					*imap;
	float				f_type;
	double				zoom;
	double				move_x;
	double				move_y;
	double				jx_mouse;
	double				jy_mouse;
	unsigned int		max_it;
	unsigned int		ex_color;
	unsigned char		gradient;
	unsigned char		j_mouse;
	unsigned char		build;
	union u_color		color;
	cl_device_id		device;
	cl_context			context;
	cl_program			program;
	cl_kernel			kernel;
	cl_command_queue	queue;
	cl_int				err;
	size_t				global_size;
	cl_mem				input_zyxtyx;
	cl_mem				input_hwicc;
	cl_mem				output;
	double				zyxtyx[6];
	unsigned int		hwicc[5];
}						data_hook;

void					start_move(char *argv);
void					mlx_start(float type);
void					preload(struct s_to_hook *data_hook);
void					start_init(struct s_to_hook *data_hook, float type);
void					draw_help(struct s_to_hook *data_hook);
void					draw_help2(struct s_to_hook *data_hook);
void					erxit(char *str);
int						ft_close(void *param);
int						all_keys(int key, void *param);
int						all_keys2(int key, struct s_to_hook *data_hook);
int						all_keys3(int key, struct s_to_hook *data_hook);
int						all_keys4(int key, struct s_to_hook *data_hook);
int						all_keys5(int key, struct s_to_hook *data_hook);
int						all_keys6(int key, struct s_to_hook *data_hook);
int						all_keys7(int key, struct s_to_hook *data_hook);
int						mouse_hook(int key, int x,
							int y, struct s_to_hook *data_hook);
int						mouse_move(int x, int y, struct s_to_hook *data_hook);
void					color_mixer(struct s_to_hook *data_hook);
void					clean_and_start(struct s_to_hook *data_hook);
void					build_all(struct s_to_hook *data_hook);
void					general(struct s_to_hook *data_hook);
void					final_general(struct s_to_hook *data_hook);
void					draw_fractal(struct s_to_hook *data_hook);
void					ocl_init(struct s_to_hook *data_hook);
cl_program				build_program(cl_context ctx, const char *filename);
cl_device_id			create_device(void);

#endif
