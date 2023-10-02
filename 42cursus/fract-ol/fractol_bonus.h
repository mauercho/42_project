/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:06:13 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/01 14:04:33 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>

# define MAX_ITER 200
# define HEIGHT 800
# define WIDTH 800
# define ESC_KEY 53
# define MOUSE_UP 4
# define MOUSE_DOWN 5
# define MAX_FLOATING_POINT 7
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define DOWN_KEY 125
# define UP_KEY 126
# define R_KEY 15
# define G_KEY 5
# define B_KEY 11
# define ZOOM_IN 1
# define ZOOM_OUT 2

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	t_complex		min;
	t_complex		max;
	t_complex		julia;
	char			*addr;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				color;
	int				bpp;
	int				size_line;
	int				endian;
	int				iter_num;
	char			*type;
}	t_data;

void	ft_putstr_fd(char *s, int fd);
void	manual(void);
void	start_julia(t_data *data);
void	start_mandelbrot(t_data *data);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
double	check_and_atod(char *str);
int		create_rgb(unsigned char r, unsigned char g, unsigned char b);
void	init_mandelbrot(t_data *data);
void	init_julia(t_data *data, char *str1, char *str2);
int		zoom(int keycode, int x, int y, t_data *data);
int		close_win(t_data *data);
int		get_key(int keycode, t_data *data);
void	init_burningship(t_data *data);
void	start_burningship(t_data *data);

#endif
