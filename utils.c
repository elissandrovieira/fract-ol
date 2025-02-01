/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:57:46 by eteofilo          #+#    #+#             */
/*   Updated: 2025/02/01 08:45:14 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}
int	scroll_up(int mouse_code, t_data *data)
{
	//printf("height = %i | width = %i\n", data->height, data->width);
	if (mouse_code == 4)
	{
		//height = data->height / 2;
		//width = data->width / 2;
		//is_in_circle(data);
		//mlx_put_image_to_window(data->mlx, data->win, data->data, 0, 0);
	}
	return (0);
}

int str_cmp(char *std, char *cmp)
{
	int i = 0;

	while (std[i])
	{
		if(std[i] != cmp[i])
			return(0);
		i++;
	}
	return (1);
}

void is_in_circle(t_data *data)
{
	int x = 0;
	int y = 0;
	int height = data->height;
	int width = data->width;

	printf("HH = %i, WW = %i\n", data->height, data->width);
	while (x <= data->width)
	{
		y = 0;
		while (y <= data->height)
		{
			double n_data = -2 + x * (4.0/data->width);
			double n_real = 2 - y * (4.0/data->height);
			if (str_cmp(data->av, "mandelbrot"))
				mandelbrot(x, y, *data);
			else if (str_cmp(data->av, "julia"))
				julia(x, y, *data);
			y++;
		}
		x++;
	}
}


