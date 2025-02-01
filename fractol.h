/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:29:55 by eteofilo          #+#    #+#             */
/*   Updated: 2025/02/01 01:16:01 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL
# define FRACTOL

# define WIDTH 800
# define HEIGHT 800

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
#include <stdio.h>

typedef struct s_data
{
	void	*data;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
	char	*av;
	int		height;
	int		width;
}	t_data;

typedef struct s_complex
{
	double	real;
	double	img;
}	t_complex;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	is_in_circle(t_data *data);
int		close_window(t_data *data);
int		scroll_up(int mouse_code, t_data *data);

void	mandelbrot(int pixel_x, int pixel_y, t_data data);
void	julia(int pixel_x, int pixel_y, t_data data);

#endif
