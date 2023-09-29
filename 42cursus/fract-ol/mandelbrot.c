/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:15:00 by minwucho          #+#    #+#             */
/*   Updated: 2023/09/29 17:44:33 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_data *data)
{
	data->min.r = -2;
	data->min.i = -1.5;
	data->max.r = 1;
	data->max.i = 1.5;
}

int	mandelbrot_set(t_complex c)
{
	double		z_r;
	double		z_i;
	t_complex	z;
	int			i;

	z.r = 0;
	z.i = 0;
	i = 0;
	while (i < MAX_ITERATION)
	{
		z_r = z.r;
		z_i = z.i;
		z.r = (z_r * z_r) - (z_i * z_i) + c.r;
		z.i = 2 * z_r * z_i + c.i;
		if (z.r * z.r + z.i * z.i > 4)
			break ;
		i++;
	}
	return (i);
}

static void	rgb_mandelbrot_make(t_data *data)
{
	data->r = ((double)data->iter_num / MAX_ITERATION) * 255;
	data->g = ((double)(data->iter_num) / (4 *  MAX_ITERATION)) * 255;
	data->b = ((double)data->iter_num / (10 * MAX_ITERATION)) * 255;
	data->color = create_rgb(data->r, data->g, data->b);
}

void	start_mandelbrot(t_data *data)
{
	int			x;
	int			y;
	t_complex	c;
	char		*addr;

	init_mandelbrot(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			c.r = (data->min.r) + (data->max.r - data->min.r) * x / (WIDTH);
			c.i = (data->min.i) + (data->max.i - data->min.i) * y / (HEIGHT);
			data->iter_num = mandelbrot_set(c);
			if (data->iter_num == MAX_ITERATION)
				data->color = create_rgb(200, 200, 200);
			else
				rgb_mandelbrot_make(data);
			addr = data->addr + (y * data->size_line + x * (data->bpp / 8));
			*(unsigned int *)addr = data->color;
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
