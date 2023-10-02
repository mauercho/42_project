/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:05:31 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/01 12:41:18 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	init_mandelbrot(t_data *data)
{
	data->min.r = -2;
	data->min.i = -1.5;
	data->max.r = 1;
	data->max.i = 1.5;
	data->r = 1;
	data->g = 1;
	data->b = 1;
	data->type = "mandelbrot";
}

static int	mandelbrot_set(t_complex c)
{
	double		z_r;
	double		z_i;
	t_complex	z;
	int			i;

	z.r = 0;
	z.i = 0;
	i = 0;
	while (i < MAX_ITER)
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

void	start_mandelbrot(t_data *p)
{
	int			x;
	int			y;
	t_complex	c;
	char		*addr;

	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			c.r = (p->min.r) + (p->max.r - p->min.r) * x / (WIDTH);
			c.i = (p->min.i) + (p->max.i - p->min.i) * y / (HEIGHT);
			p->iter_num = mandelbrot_set(c);
			if (p->iter_num == MAX_ITER)
				p->color = create_rgb(p->r, p->g, p->b);
			else
				p->color = create_rgb(p->r, p->g, p->b) * p->iter_num;
			addr = p->addr + (y * p->size_line + x * (p->bpp / 8));
			*(unsigned int *)addr = p->color;
		}
	}
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
}
