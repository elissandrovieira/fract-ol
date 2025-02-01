/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:28:41 by eteofilo          #+#    #+#             */
/*   Updated: 2025/02/01 10:15:47 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(int pixel_x, int pixel_y, t_data data)
{
	t_complex	z;
	t_complex	c;
	double		temp_real;
	int			i;

	z.real = 0;
	z.img = 0;
    //c.real = MOV + pixel_x *(ZOOM / W || H)
	c.real = -3 + pixel_x * (2.0 / WIDTH);
	c.img = 1.5 - pixel_y * (2.0 / HEIGHT);
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
