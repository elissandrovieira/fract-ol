/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:42:58 by eteofilo          #+#    #+#             */
/*   Updated: 2025/02/07 18:27:47 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(int pixel_x, int pixel_y, t_data *data)
{
	t_complex	z;
	t_complex	c;
	double		temp_real;
	int			i;

	z.real = data->position_x + pixel_x * data->zoom;
	z.img = data->position_y - pixel_y * data->zoom;
	c.real = ft_atoi(data->av[2]);
	c.img = ft_atoi(data->av[3]);
	i = 0;
	while (((z.img * z.img) + (z.real * z.real) <= 4 * 4) && i < 100)
	{
		temp_real = (z.real * z.real) - (z.img * z.img);
		z.img = 2 * z.real * z.img;
		z.real = temp_real;
		z.real += c.real;
		z.img += c.img;
		i++;
	}
	if (i == 100)
		my_mlx_pixel_put(data, pixel_x, pixel_y, 0x00ffffff);
	else
		my_mlx_pixel_put(data, pixel_x, pixel_y, i * 0x0001000a);
}
