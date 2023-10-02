/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:50:00 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/01 12:40:56 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	zoom_in_out(t_data *data, double r, double i, int inout)
{
	double	width;
	double	height;

	width = data->max.r - data->min.r;
	height = data->max.r - data->min.r;
	if (inout == ZOOM_OUT)
	{
		width *= 1.5;
		height *= 1.5;
		data->min.r = r - width / 2.0;
		data->min.i = i - height / 2.0;
		data->max.r = r + width / 2.0;
		data->max.i = i + height / 2.0;
	}
	else if (inout == ZOOM_IN)
	{
		width /= 1.5;
		height /= 1.5;
		data->min.r = r - width / 2.0;
		data->min.i = i - height / 2.0;
		data->max.r = r + width / 2.0;
		data->max.i = i + height / 2.0;
	}
}

static void	change_rgb(int keycode, t_data *data)
{
	if (keycode == R_KEY)
		data->r += 10;
	else if (keycode == G_KEY)
		data->g += 10;
	else if (keycode == B_KEY)
		data->b += 10;
}

static void	change_dir(int keycode, t_data *data)
{
	double	x;
	double	y;

	x = data->max.r - data->min.r;
	y = data->max.i - data->min.i;
	if (keycode == UP_KEY)
	{
		data->min.i -= y * 0.1;
		data->max.i -= y * 0.1;
	}
	else if (keycode == DOWN_KEY)
	{
		data->min.i += y * 0.1;
		data->max.i += y * 0.1;
	}
	else if (keycode == RIGHT_KEY)
	{
		data->min.r += x * 0.1;
		data->max.r += x * 0.1;
	}
	else if (keycode == LEFT_KEY)
	{
		data->min.r -= x * 0.1;
		data->max.r -= x * 0.1;
	}
}

int	zoom(int keycode, int x, int y, t_data *data)
{
	t_complex	cen;

	cen.r = (data->min.r) + (data->max.r - data->min.r) * x / (WIDTH);
	cen.i = (data->min.i) + (data->max.i - data->min.i) * y / (HEIGHT);
	if (keycode == MOUSE_UP)
		zoom_in_out(data, cen.r, cen.i, ZOOM_IN);
	else if (keycode == MOUSE_DOWN)
		zoom_in_out(data, cen.r, cen.i, ZOOM_OUT);
	if (ft_strcmp(data->type, "mandelbrot") == 0)
		start_mandelbrot(data);
	else if (ft_strcmp(data->type, "julia") == 0)
		start_julia(data);
	else if (ft_strcmp(data->type, "burningship") == 0)
		start_burningship(data);
	return (0);
}

int	get_key(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_win(data);
	else if (keycode == R_KEY || keycode == G_KEY || keycode == B_KEY)
		change_rgb(keycode, data);
	else if (keycode >= LEFT_KEY && keycode <= UP_KEY)
		change_dir(keycode, data);
	if (ft_strcmp(data->type, "mandelbrot") == 0)
		start_mandelbrot(data);
	else if (ft_strcmp(data->type, "julia") == 0)
		start_julia(data);
	else if (ft_strcmp(data->type, "burningship") == 0)
		start_burningship(data);
	return (0);
}
