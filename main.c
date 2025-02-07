/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:03:29 by eteofilo          #+#    #+#             */
/*   Updated: 2025/02/07 18:27:47 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int check_args(int ac, char **av);

int	main(int ac, char **av)
{
	t_data	data;
	//printf("%f\n", ft_atoi("5.45"));
	if (!check_args(ac, av))
		return (0);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Hello world!");
	data.data = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.data, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	data.av = av;
	data.position_x = -2;
	data.position_y = 2;
	data.zoom = 4.0 / WIDTH;
	draw_fractal(&data, 0, 0);
	mlx_put_image_to_window(data.mlx, data.win, data.data, 0, 0);
	mlx_mouse_hook(data.win, scroll_up, &data);
	mlx_key_hook(data.win, movement, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!data->addr)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
