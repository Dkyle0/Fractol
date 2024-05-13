__kernel void solve_g(__global int *r_color,
					  __global double const *zyxtyx,
					  __global unsigned int const *hwicc)
{
    // Get Parallel Index
    unsigned int it = 0;
	long double	zx;
	long double	zy;
	double h;
	double w;
	long double	xtemp;
	long double	ytemp;
	long double cx;
	long double cy;
	int x;
	int y;

	x = get_global_id(0) % hwicc[0];
	y = get_global_id(0) / hwicc[1];
	h = hwicc[0];
	w = hwicc[1];
	if (zyxtyx[3] == 1)
	{
		zx = -2 * ((double)(h / 2 - x + zyxtyx[2])) / zyxtyx[0] / h * 3.5;	
		zy = -1.5 * ((double)(h / 2 - y + zyxtyx[1])) / zyxtyx[0] / h * 2.5;
		while ((zx * zx + zy * zy < 4) & (it < hwicc[2]))
		{
			xtemp = zx * zx - zy * zy;
			zy = 2 * zx * zy + zyxtyx[4]; 
			zx = xtemp + zyxtyx[5]; 
			it++;
		}
		if (it >= hwicc[2])
			r_color[get_global_id(0)] = hwicc[3];
		else
		{
			if (hwicc[4] != 0x000000)
				r_color[get_global_id(0)] = hwicc[4] * it;
			else
				r_color[get_global_id(0)] = hwicc[4] + 30 * it;
		}
	}
	else if (zyxtyx[3] == 2)
	{
		zx = 0;	
		zy = 0;
		while ((zx * zx + zy * zy < 4) & (it < hwicc[2]))
		{
			xtemp = zx * zx - zy * zy + -2 * ((double)(h / 2 - x + zyxtyx[2])) / zyxtyx[0] / h * 3.5;
			zy = 2 * zx * zy + -1.5 * ((double)(h / 2 - y + zyxtyx[1])) / zyxtyx[0] / h * 2.5; 
			zx = xtemp; 
			it++;
		}
		if (it >= hwicc[2])
			r_color[get_global_id(0)] = hwicc[3];
		else
		{
			if (hwicc[4] != 0x000000)
				r_color[get_global_id(0)] = hwicc[4] * it;
			else
				r_color[get_global_id(0)] = hwicc[4] + 30 * it;
		}
	}
	else if (zyxtyx[3] == 3)
	{
		zx = -2 * ((double)(w / 2 - x + w / 100 * 52.27 + zyxtyx[2])) / zyxtyx[0] / w * 4;
		zy = 2 * ((double)(w / 2 - y + h / 100 * 26.1363 + zyxtyx[1])) / zyxtyx[0] / w * 4;
		cx = zx;
		cy = zy;
		while ((zx * zx + zy * zy <= 16) & (it < hwicc[2]))
		{
			zx = zx * zx - zy * zy + cx;
			zy = 2 * zx * zy + cy;
			cx = cx / 2 + zx;
			cy = cy / 2 + zy;
			it++;
		}
		if (it >= hwicc[2])
			r_color[get_global_id(0)] = hwicc[3];
		else
		{
			if (hwicc[4] != 0x000000)
				r_color[get_global_id(0)] = hwicc[4] * it;
			else
				r_color[get_global_id(0)] = hwicc[4] + 30 * it;
		}
	}
	else if (zyxtyx[3] == 4)
	{
		zx = -2.5 * ((double)(h / 2 - x + zyxtyx[2])) / zyxtyx[0] / h * 3.5;
		zy = -1 * ((double)(w / 2 - y + h / 100 * 26.1363  + zyxtyx[1])) / zyxtyx[0] / w * 2;
		cx = zx;
		cy = zy;
		while ((cx * cx + cy * cy < 4) & (it < hwicc[2]))
		{
			xtemp = cx * cx - cy * cy + zx;
			if (cx * cy > 0)
				cy = 2 * cx * cy + zy;
			else
				cy = (2 * cx * cy) * -1 + zy ;
			if (xtemp > 0)
				cx = xtemp;
			else
				cx = xtemp * -1;
			it++;
		}
		if (it >= hwicc[2])
			r_color[get_global_id(0)] = hwicc[3];
		else
		{
			if (hwicc[4] != 0x000000)
				r_color[get_global_id(0)] = hwicc[4] * it;
			else
				r_color[get_global_id(0)] = hwicc[4] + 30 * it;
		}
	}
	else if (zyxtyx[3] == 5)
	{
		zx = -2.5 * ((double)(h / 2 - x + zyxtyx[2])) / zyxtyx[0] / h * 3.5;
		zy = -1 * ((double)(w / 2 - y + h / 100 * 26.1363 + zyxtyx[1])) / zyxtyx[0] / w * 2;
		cx = zx;
		cy = zy;
		while ((zx * zx + zy * zy < 4) & (it < hwicc[2]))
		{
			xtemp = zx * zx - zy * zy + cx;
			zy = -2 * zx * zy + cy;
			zx = xtemp;
			it++;
		}
		if (it >= hwicc[2])
			r_color[get_global_id(0)] = hwicc[3];
		else
		{
			if (hwicc[4] != 0x000000)
				r_color[get_global_id(0)] = hwicc[4] * it;
			else
				r_color[get_global_id(0)] = hwicc[4] + 30 * it;
		}
	}
}
