/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 17:56:43 by dkyle             #+#    #+#             */
/*   Updated: 2019/06/30 17:56:44 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ocl_init(struct s_to_hook *data_hook)
{
	data_hook->global_size = data_hook->height * data_hook->weight;
	data_hook->zyxtyx[0] = data_hook->zoom;
	data_hook->zyxtyx[1] = data_hook->move_y;
	data_hook->zyxtyx[2] = data_hook->move_x;
	data_hook->zyxtyx[3] = data_hook->f_type;
	data_hook->zyxtyx[4] = data_hook->jy_mouse;
	data_hook->zyxtyx[5] = data_hook->jx_mouse;
	data_hook->hwicc[0] = data_hook->height;
	data_hook->hwicc[1] = data_hook->weight;
	data_hook->hwicc[2] = data_hook->max_it;
	data_hook->hwicc[3] = data_hook->color.rgb;
	data_hook->hwicc[4] = data_hook->ex_color;
}

cl_device_id	create_device(void)
{
	cl_platform_id	platform;
	cl_device_id	dev;
	int				err;

	err = clGetPlatformIDs(1, &platform, NULL);
	if (err < 0)
		erxit("Get Platform ID error");
	if ((err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1,
		&dev, NULL)) == CL_DEVICE_NOT_FOUND)
		err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_CPU, 1, &dev, NULL);
	if (err < 0)
		erxit("Couldn't access any devices");
	return (dev);
}

cl_program		build_program(cl_context ctx, const char *filename)
{
	cl_program		program;
	int				fd;
	char			*program_buffer;
	size_t			program_size;
	int				err;

	program_buffer = (char*)malloc(16384 + 1);
	program_buffer[16384] = '\0';
	fd = open(filename, O_RDONLY);
	program_size = read(fd, program_buffer, 16384);
	close(fd);
	program = clCreateProgramWithSource(ctx, 1,
	(const char**)&program_buffer, &program_size, &err);
	if (err < 0)
		erxit("Couldn't create the program");
	free(program_buffer);
	err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
	if (err < 0)
		erxit("Couldn't build the program");
	return (program);
}

void			build_all(struct s_to_hook *data_hook)
{
	data_hook->device = create_device();
	data_hook->context = clCreateContext(NULL, 1,
		&data_hook->device, NULL, NULL, &data_hook->err);
	if (!data_hook->context)
		erxit("Error: Failed to create a compute context!");
	data_hook->program = build_program(data_hook->context, "src/fr.cl");
	data_hook->queue = clCreateCommandQueue(data_hook->context,
		data_hook->device, 0, &data_hook->err);
	if (!data_hook->queue)
		erxit("Error: Failed to create a command commands!");
	data_hook->kernel = clCreateKernel(data_hook->program,
		"solve_g", &data_hook->err);
}
