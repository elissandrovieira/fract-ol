/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:03:29 by eteofilo          #+#    #+#             */
/*   Updated: 2025/02/07 11:01:24 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		return (0);
	}
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Hello world!");
	data.data = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(
		data.data, &data.bits_per_pixel,&data.line_length,&data.endian
	);

	data.av = av[1];
	data.height = HEIGHT;
	data.width = WIDTH;
	data.p_x = -2;
	data.p_y = 1.5;
	data.zoom = 0;
	data.size = 0;

	is_in_circle(&data, 0, 0);
	mlx_put_image_to_window(data.mlx, data.win, data.data, 0, 0);
	mlx_mouse_hook(data.win, scroll_up, &data);
	mlx_key_hook(data.win, movement, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
