/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:40:29 by songevor          #+#    #+#             */
/*   Updated: 2024/08/06 14:40:30 by songevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fract)
{
	if (!(ft_strncmp(fract->name, "julia", 5)))
	{
		c->x = fract->julia_x;
		c->y = fract->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	my_pixel_put(int x, int y, t_image *image, int color)
{
	int	offset;

	offset = (y * image->line_len) + (x * (image->bit_pix / 8));
	*(unsigned int *)(image->pixel_ptr + offset) = color;
}

void	pixel_handle(int x, int y, t_fractal *fract)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, -2, +2, WIDTH) * fract->zoom) + fract->shift_x;
	z.y = (map(y, +2, -2, HEIGHT) * fract->zoom) + fract->shift_y;
	mandel_vs_julia(&z, &c, fract);
	while (i < fract->iteration_def)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fract->escape_value)
		{
			color = map(i, NAVY, PURPLE, fract->iteration_def);
			my_pixel_put(x, y, &fract->image, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fract->image, BLACK);
}

void	render(t_fractal *fract)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pixel_handle(x, y, fract);
		}
	}
	mlx_put_image_to_window(fract->mlx_connect, \
				fract->mlx_window, fract->image.image_ptr, 0, 0);
}
