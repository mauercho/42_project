/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:57:11 by minwucho          #+#    #+#             */
/*   Updated: 2023/09/29 18:20:46 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_win(t_data *p)
{
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	mlx_destroy_image(p->mlx_ptr, p->img_ptr);
	mlx_destroy_window(p->mlx_ptr, p->win_ptr);
	exit (0);
}

void	open_win(t_data *data, char *str)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, str);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img_ptr, \
			&data->bpp, &data->size_line, &data->endian);
}

void	start_program(char **av)
{
	t_data	data;

	open_win(&data, av[1]);
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		start_mandelbrot(&data);
	else if (ft_strcmp(av[1], "julia") == 0)
		start_julia(&data, av[2], av[3]);
	mlx_mouse_hook(params.win, zoom, &params);
	mlx_key_hook(params.win, get_key, &params);
	mlx_hook(params.win, 17, 1L << 17, close_win, &params);
	mlx_loop((&data)->mlx_ptr);
}

int	main(int ac, char **av)
{
	if (ac == 2 || ac == 4)
	{
		if (ft_strcmp(av[1], "mandelbrot") == 0 && !av[2])
			start_program(av);
		else if (ft_strcmp(av[1], "julia") == 0 && av[2] && av[3])
			start_program(av);
		else
			manual();
	}
	else
		manual();
	return (0);
}
