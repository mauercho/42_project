/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:06:24 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/01 12:39:04 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	init_julia(t_data *data, char *str1, char *str2)
{
	data->julia.r = check_and_atod(str1);
	data->julia.i = check_and_atod(str2);
	data->min.r = -2.0;
	data->min.i = -2.0;
	data->max.r = 2.0;
	data->max.i = 2.0;
	data->r = 1;
	data->g = 1;
	data->b = 1;
	data->type = "julia";
}

static int	julia_set(t_complex c, double real_part, double img_part)
{
	double		z_r;
	double		z_i;
	t_complex	new;
	int			i;

	i = 0;
	z_r = c.r;
	z_i = c.i;
	while (i < MAX_ITER)
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

void	start_julia(t_data *p)
{
	t_complex	c;
	int			x;
	int			y;
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
			p->iter_num = julia_set(c, p->julia.r, p->julia.i);
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
