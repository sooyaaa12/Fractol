/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:39:45 by songevor          #+#    #+#             */
/*   Updated: 2024/08/06 14:40:13 by songevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	malloc_error(void)
{
	perror("Malloc error");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractal *fract)
{
	fract->escape_value = 4;
	fract->iteration_def = 42;
	fract->shift_x = 0.0;
	fract->shift_y = 0.0;
	fract->zoom = 1.0;
}

void	events_init(t_fractal *fract)
{
	mlx_key_hook(fract->mlx_window, key_handler, fract);
	mlx_mouse_hook(fract->mlx_window, mouse_handler, fract);
	mlx_hook(fract->mlx_window, 17, 0, close_handler, fract);
	mlx_hook(fract->mlx_window, 6, 0, julia_track, fract);
}

void	fract_init(t_fractal *fract)
{
	fract->mlx_connect = mlx_init();
	if (fract->mlx_connect == NULL)
		malloc_error();
	fract->mlx_window = mlx_new_window(fract->mlx_connect,
			WIDTH, HEIGHT, fract->name);
	if (fract->mlx_window == NULL)
	{
		free(fract->mlx_window);
		malloc_error();
	}
	fract->image.image_ptr = mlx_new_image(fract->mlx_connect, WIDTH, HEIGHT);
	if (fract->image.image_ptr == NULL)
	{
		mlx_destroy_window(fract->mlx_connect, fract->mlx_window);
		free(fract->mlx_connect);
		malloc_error();
	}
	fract->image.pixel_ptr = mlx_get_data_addr(fract->image.image_ptr,
			&fract->image.bit_pix, &fract->image.line_len,
			&fract->image.endian);
	events_init(fract);
	data_init(fract);
}
