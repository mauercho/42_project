/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:07:10 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/01 12:38:51 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	init_burningship(t_data *data)
{
	data->min.r = -2.0;
	data->min.i = -1.5;
	data->max.r = 2.0;
	data->max.i = 2.0;
	data->r = 1;
	data->g = 1;
	data->b = 1;
	data->type = "burningship";
}

static int	burning_set(t_complex c)
{
	double	z_r;
	double	z_i;
	int		i;
	double	temp;

	i = 0;
	z_r = 0;
	z_i = 0;
	while (i < MAX_ITER)
	{
		z_r = fabs(z_r);
		z_i = fabs(z_i);
		temp = z_r;
		z_r = z_r * z_r - z_i * z_i + c.r;
		z_i = 2 * temp * z_i + c.i;
		if (z_r * z_r + z_i * z_i > 4)
			break ;
		i++;
	}
	return (i);
}

void	start_burningship(t_data *p)
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
			p->iter_num = burning_set(c);
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
