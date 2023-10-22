/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:35:22 by dkyle             #+#    #+#             */
/*   Updated: 2019/06/06 13:35:24 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(struct s_to_hook *data_hook)
{
	size_t	ibn;
	int		nx;
	int		ny;

	ibn = 0;
	nx = 0;
	ny = 0;
	while (ibn <= data_hook->global_size)
	{
		if (nx >= data_hook->height)
		{
			nx = 0;
			ny++;
		}
		*(int *)&data_hook->addr_ptr[(nx * data_hook->bpp / 8) +
			(ny * data_hook->size_line)] = data_hook->imap[ibn];
		nx++;
		ibn++;
	}
	mlx_put_image_to_window(data_hook->mlx_ptr,
		data_hook->win_ptr, data_hook->img_ptr, 0, 0);
}

void	final_general(struct s_to_hook *data_hook)
{
	if (data_hook->err != CL_SUCCESS)
		erxit("Error: Failed to execute kernel!");
	clEnqueueReadBuffer(data_hook->queue, data_hook->output, CL_TRUE, 0,
		sizeof(int) * data_hook->global_size, data_hook->imap, 0, NULL, NULL);
	draw_fractal(data_hook);
	clReleaseMemObject(data_hook->input_hwicc);
	clReleaseMemObject(data_hook->input_zyxtyx);
	clReleaseMemObject(data_hook->output);
}

void	general(struct s_to_hook *data_hook)
{
	ocl_init(data_hook);
	data_hook->input_zyxtyx = clCreateBuffer(data_hook->context,
		CL_MEM_READ_ONLY, sizeof(double*) * 6, NULL, NULL);
	data_hook->input_hwicc = clCreateBuffer(data_hook->context,
		CL_MEM_READ_ONLY, sizeof(unsigned int*) * 5, NULL, NULL);
	data_hook->output = clCreateBuffer(data_hook->context, CL_MEM_WRITE_ONLY,
		sizeof(int*) * data_hook->height * data_hook->weight, NULL, NULL);
	data_hook->err = clSetKernelArg(data_hook->kernel,
		0, sizeof(cl_mem), &data_hook->output);
	data_hook->err = clSetKernelArg(data_hook->kernel, 1,
		sizeof(cl_mem), &data_hook->input_zyxtyx);
	data_hook->err = clSetKernelArg(data_hook->kernel, 2,
		sizeof(cl_mem), &data_hook->input_hwicc);
	data_hook->err = clEnqueueWriteBuffer(data_hook->queue,
		data_hook->input_hwicc, CL_TRUE, 0, sizeof(unsigned int*)
		* 5, data_hook->hwicc, 0, NULL, NULL);
	data_hook->err = clEnqueueWriteBuffer(data_hook->queue,
		data_hook->input_zyxtyx, CL_TRUE, 0, sizeof(double*)
		* 6, data_hook->zyxtyx, 0, NULL, NULL);
	data_hook->err = clEnqueueWriteBuffer(data_hook->queue, data_hook->output,
		CL_TRUE, 0, sizeof(int) * data_hook->global_size, data_hook->imap,
		0, NULL, NULL);
	data_hook->err = clEnqueueNDRangeKernel(data_hook->queue, data_hook->kernel,
		1, NULL, &data_hook->global_size, NULL, 0, NULL, NULL);
	final_general(data_hook);
}
