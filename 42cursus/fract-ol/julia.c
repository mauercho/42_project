/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:15:07 by minwucho          #+#    #+#             */
/*   Updated: 2023/09/29 17:45:54 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_data *data, char *str1, char *str2)
{
	data->julia.r = check_and_atod(str1);
	data->julia.i = check_and_atod(str2);
	data->min.r = -2.0;
	data->min.i = -2.0;
	data->max.r = 2.0;
	data->max.i = 2.0;
}

int	julia_set(t_complex c, double real_part, double img_part)
{
	double		z_r;
	double		z_i;
	t_complex	new;
	int			i;

	i = 0;
	z_r = c.r;
	z_i = c.i;
	while (i < MAX_ITERATION)
	{
		new.r = (z_r * z_r) - (z_i * z_i) + real_part;
		new.i = (2 * z_r * z_i) + img_part;
		z_r = new.r;
		z_i = new.i;
		if (new.r * new.r + new.i * new.i > 4)
			break ;
		i++;
	}
	return (i);
}

static void	rgb_julia_make(t_data *data)
{
	data->r = ((double)data->iter_num / MAX_ITERATION) * 255;
	data->g = ((double)(data->iter_num) / (2 *  MAX_ITERATION)) * 255;
	data->b = ((double)data->iter_num / (3 * MAX_ITERATION)) * 255;
	data->color = create_rgb(data->r, data->g, data->b);
}

void	start_julia(t_data *data, char *str1, char *str2)
{
	t_complex	c;
	int			x;
	int			y;
	char		*addr;

	init_julia(data, str1, str2);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			c.r = (data->min.r) + (data->max.r - data->min.r) * x / (WIDTH);
			c.i = (data->min.i) + (data->max.i - data->min.i) * y / (HEIGHT);
			data->iter_num = julia_set(c, data->julia.r, data->julia.i);
			if (data->iter_num == MAX_ITERATION)
				data->color = create_rgb(MAX_ITERATION, MAX_ITERATION, MAX_ITERATION);
			else
				rgb_julia_make(data);
			addr = data->addr + (y * data->size_line + x * (data->bpp / 8));
			*(unsigned int *)addr = data->color;
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
