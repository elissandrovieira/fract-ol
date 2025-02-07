/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:51:43 by eteofilo          #+#    #+#             */
/*   Updated: 2025/02/07 18:27:47 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	scroll_up(int mousecode, int x, int y, t_data *data)
{
	if (mousecode == 4)
		data->zoom /= 1.3;
	if (mousecode == 5)
		data->zoom *= 1.3;
	draw_fractal(data, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->data, 0, 0);
	return (0);
}

int	movement(int keycode, t_data *data)
{
	if (keycode == 65362 || keycode == 119)
		data->position_y += data->zoom * 100;
	else if (keycode == 65364 || keycode == 115)
		data->position_y -= data->zoom * 100;
	else if (keycode == 65361 || keycode == 97)
		data->position_x -= data->zoom * 100;
	else if (keycode == 65363 || keycode == 100)
		data->position_x += data->zoom * 100;
	else if (keycode == 65307)
		close_window(data);
	draw_fractal(data, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->data, 0, 0);
	return (0);
}

void	draw_fractal(t_data *data, float mov_x, float mov_y)
{
	int x;
	int y;

	x = mov_x;
	while (x < WIDTH)
	{
		y = mov_y;
		while (y < HEIGHT)
		{
			if (ft_strcmp(data->av[1], "mandelbrot"))
				mandelbrot(x, y, data);
			else if (ft_strcmp(data->av[1], "julia"))
				julia(x, y, data);
			y++;
		}
		x++;
	}
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}
