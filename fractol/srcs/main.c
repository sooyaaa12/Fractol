/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:39:39 by songevor          #+#    #+#             */
/*   Updated: 2024/08/06 14:40:23 by songevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fract;

	if ((argc == 2 && !(ft_strncmp(argv[1], "mandelbrot", 11)))
		|| (argc == 4 && !(ft_strncmp(argv[1], "julia", 6))))
	{
		fract.name = argv[1];
		if (argc == 4)
		{
			fract.julia_x = float_atoi(argv[2]);
			fract.julia_y = float_atoi(argv[3]);
		}
		fract_init(&fract);
		render(&fract);
		mlx_loop(fract.mlx_connect);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, 1);
		exit(EXIT_FAILURE);
	}
}
