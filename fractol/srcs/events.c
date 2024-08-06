/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:40:05 by songevor          #+#    #+#             */
/*   Updated: 2024/08/06 14:40:07 by songevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	close_handler(t_fractal *fract)
{
	mlx_destroy_window(fract->mlx_connect, fract->mlx_window);
	exit(0);
}

int	key_handler(int keysym, t_fractal *fract)
{
	if (keysym == 53)
		close_handler(fract);
	else if (keysym == 123)
		fract->shift_x -= (0.5 * fract->zoom);
	else if (keysym == 124)
		fract->shift_x += (0.5 * fract->zoom);
	else if (keysym == 126)
		fract->shift_y += (0.5 * fract->zoom);
	else if (keysym == 125)
		fract->shift_y -= (0.5 * fract->zoom);
	else if (keysym == 69)
		fract->iteration_def += 10;
	else if (keysym == 78)
		fract->iteration_def -= 10;
	destroy(fract);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fract)
{
	(void)x;
	(void)y;
	if (button == 5)
		fract->zoom *= 0.9;
	else if (button == 4)
		fract->zoom *= 1.05;
	destroy(fract);
	return (0);
}

void	destroy(t_fractal *fract)
{
	mlx_clear_window(fract->mlx_connect, fract->mlx_window);
	render(fract);
}

int	julia_track(int x, int y, t_fractal *fract)
{
	if (!ft_strncmp(fract->name, "julia", 5))
	{
		fract->julia_x = (map(x, -2, +2, WIDTH) * fract->zoom) + fract->shift_x;
		fract->julia_y = (map(y, +2, -2, HEIGHT)
				* fract->zoom) + fract->shift_y;
		destroy(fract);
	}
	return (0);
}
