/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:57:46 by eteofilo          #+#    #+#             */
/*   Updated: 2025/02/07 18:12:25 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *std, char *cmp)
{
	int	i;

	i = 0;
	while (std[i] || cmp[i])
	{
		if (std[i] != cmp[i])
			return (0);
		i++;
	}
	return (1);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

double ft_atoi(char *str)
{
	double	n;
	int		dot;
	int		signal;

	n = 0;
	dot = 0;
	signal = 1;
	while(*str)
	{
		if (*str == str[0] && *str == '-')
			signal = -1;
		if (*str == '.')
			dot = 1;
		else if (dot == 0 && *str >= 48 && *str <= 57)
			n = n * 10.0 + (*str - 48.0);
		else if (dot >0 && *str >= 48 && *str <= 57)
		{
			n += (double)(*str - 48) / (10.0 * dot);
			dot *= 10;
		}
		str++;
	}
	return ((double)n * signal);
}

int is_number(char *x, char *y)
{
	if (*x == '-' || *x == '+')
		x++;
	while((*x >= '0' && *x <= '9') || *x == '.')
		x++;
	if (*y == '-' || *y == '+')
		y++;
	while((*y >= '0' && *y <= '9') || *y == '.')
		y++;
	if (*x != '\0' || *y != '\0')
		return (0);
	return (1);
}

int check_args(int ac, char **av)
{
	if (
		(ft_strcmp(av[1], "mandelbrot") && ac == 2) ||
		(ft_strcmp(av[1], "julia") && ac == 4 && is_number(av[2], av[3]))
		)
		return (1);
	else
	{
		ft_putstr("----------------------------------------\n");
		ft_putstr("|             FRACT-OL USAGE           |\n");
		ft_putstr("----------------------------------------\n");
		ft_putstr("|                Type:                 |\n");
		ft_putstr("|        ./fractol mandelbrot          |\n");
		ft_putstr("|    ./fractol julia <int> <int>       |\n");
		ft_putstr("----------------------------------------\n");
		return (0);
	}
}


