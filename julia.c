/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:42:58 by eteofilo          #+#    #+#             */
/*   Updated: 2025/02/07 11:00:05 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(int pixel_x, int pixel_y, t_data data)
{
	t_complex	z;
	t_complex	c;
	double		temp_real;
	int			i;

	z.real = -2 + pixel_x * (4.0 / WIDTH);
	z.img = 2 - pixel_y * (4.0 / HEIGHT);
	c.real = -0.7269;
	c.img = 0.1889;
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
		my_mlx_pixel_put(&data, pixel_x, pixel_y, 0x00440000);
	else
		my_mlx_pixel_put(&data, pixel_x, pixel_y, i * 0x00004400);
}
