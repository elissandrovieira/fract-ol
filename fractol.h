/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:53:25 by eteofilo          #+#    #+#             */
/*   Updated: 2025/02/07 18:27:47 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_data
{
	void	*data;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
	char	**av;
	int		height;
	int		width;
	float	zoom;
	float	position_x;
	float	position_y;
}			t_data;

typedef struct s_complex
{
	double	real;
	double	img;
}			t_complex;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		draw_fractal(t_data *data, float mov_x, float mov_y);
int			close_window(t_data *data);
int			ft_strcmp(char *std, char *cmp);
int 		check_args(int ac, char **av);
double 		ft_atoi(char *str);
int			scroll_up(int mousecode, int x, int y, t_data *data);
int			movement(int keycode, t_data *data);

void		mandelbrot(int pixel_x, int pixel_y, t_data *data);
void		julia(int pixel_x, int pixel_y, t_data *data);

#endif
