/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:56:02 by minwucho          #+#    #+#             */
/*   Updated: 2023/09/30 20:23:03 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_out(t_data *data, double r, double i)
{
	double	width;
	double	height;

	width = data->max.r - data->min.r;
	height = data->max.r - data->min.r;
	width *= 1.5;
	height *= 1.5;
	data->min.r = r - width / 2.0;
	data->min.i = i - height / 2.0;
	data->max.r = r + width / 2.0;
	data->max.i = i + height / 2.0;
}

static void	zoom_in(t_data *data, double r, double i)
{
	double	width;
	double	height;

	width = data->max.r - data->min.r;
	height = data->max.r - data->min.r;
	width /= 1.5;
	height /= 1.5;
	data->min.r = r - width / 2.0;
	data->min.i = i - height / 2.0;
	data->max.r = r + width / 2.0;
	data->max.i = i + height / 2.0;
}

int	zoom(int keycode, int x, int y, t_data *data)
{
	t_complex	cen;

	cen.r = (data->min.r) + (data->max.r - data->min.r) * x / (WIDTH);
	cen.i = (data->min.i) + (data->max.i - data->min.i) * y / (HEIGHT);
	if (keycode == MOUSE_UP)
		zoom_in(data, cen.r, cen.i);
	else if (keycode == MOUSE_DOWN)
		zoom_out(data, cen.r, cen.i);
	if (ft_strcmp(data->type, "mandelbrot") == 0)
		start_mandelbrot(data);
	else if (ft_strcmp(data->type, "julia") == 0)
		start_julia(data);
	return (0);
}

int	get_key(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_win(data);
	return (0);
}
