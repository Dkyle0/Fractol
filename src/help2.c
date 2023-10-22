/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 18:00:51 by dkyle             #+#    #+#             */
/*   Updated: 2019/06/30 18:00:53 by dkyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	all_keys7(int key, struct s_to_hook *data_hook)
{
	if (key == 23)
	{
		data_hook->f_type = 5;
		clean_and_start(data_hook);
	}
	return (0);
}

int	all_keys6(int key, struct s_to_hook *data_hook)
{
	if (key == 76)
	{
		if (data_hook->ex_color == 0x000000)
			data_hook->ex_color = 0x2a9182;
		else if (data_hook->ex_color == 0x2a9182)
			data_hook->ex_color = 0x730096;
		else if (data_hook->ex_color == 0x730096)
			data_hook->ex_color = 0x966200;
		else if (data_hook->ex_color == 0x966200)
			data_hook->ex_color = 0xa60f0f;
		else if (data_hook->ex_color == 0xa60f0f)
			data_hook->ex_color = 0x009600;
		else
			data_hook->ex_color = 0x000000;
		clean_and_start(data_hook);
	}
	if (key == 83)
	{
		data_hook->gradient = 4;
		color_mixer(data_hook);
		clean_and_start(data_hook);
	}
	return (all_keys7(key, data_hook));
}

int	all_keys5(int key, struct s_to_hook *data_hook)
{
	if (key == 67)
	{
		if (data_hook->color.rgb == 0xc42121)
			data_hook->color.rgb = 0xffb52d;
		else if (data_hook->color.rgb == 0xffb52d)
			data_hook->color.rgb = 0x000000;
		else
			data_hook->color.rgb = 0xc42121;
		clean_and_start(data_hook);
	}
	if (key == 84)
	{
		data_hook->gradient = 5;
		color_mixer(data_hook);
		clean_and_start(data_hook);
	}
	if (key == 85)
	{
		data_hook->gradient = 6;
		color_mixer(data_hook);
		clean_and_start(data_hook);
	}
	return (all_keys6(key, data_hook));
}

int	all_keys4(int key, struct s_to_hook *data_hook)
{
	if (key == 20)
	{
		data_hook->f_type = 3;
		clean_and_start(data_hook);
	}
	if (key == 21)
	{
		data_hook->f_type = 4;
		clean_and_start(data_hook);
	}
	if (key == 24)
	{
		data_hook->max_it += 10;
		clean_and_start(data_hook);
	}
	if (key == 27)
	{
		if (data_hook->max_it > 10)
			data_hook->max_it -= 10;
		clean_and_start(data_hook);
	}
	return (all_keys5(key, data_hook));
}
