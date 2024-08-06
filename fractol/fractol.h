/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:40:50 by songevor          #+#    #+#             */
/*   Updated: 2024/08/06 14:40:51 by songevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"

# define HEIGHT 800
# define WIDTH 800
# define ERROR_MESSAGE "Invalid input"

# define NAVY           0x001F3F
# define BLUE           0x0074D9
# define AQUA           0x7FDBFF
# define TEAL           0x39CCCC
# define OLIVE          0x3D9970
# define GREEN          0x2ECC40
# define LIME           0x01FF70
# define YELLOW         0xFFDC00
# define ORANGE         0xFF851B
# define RED            0xFF4136
# define MAROON         0x85144B
# define FUCHSIA        0xF012BE
# define PURPLE         0xB10DC9
# define BLACK          0x111111
# define GRAY           0xAAAAAA
# define SILVER         0xDDDDDD
# define WHITE          0xFFFFFF

# define XK_ESCAPE		0xff1b
# define XK_LEFT 		0xff51
# define XK_RIGHT		0xff53
# define XK_UP			0xff52
# define XK_DOWN		0xff54
# define XK_PLUS		0x002b
# define XK_MINUS		0x002d
// # define KEYPRESS				2
// # define KEYPRESSMASK			0
// # define BUTTONPRESS			4
// # define BUTTONPRESSMASK		(1L<<BUTTONPRESS)
// # define DESTROYNOTIFY			17
// # define STRUCTURENOTIFYMASK	(1L<<19)

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_image
{
	void	*image_ptr; //pointer to image struct
	char	*pixel_ptr; //points to pixel
	int		bit_pix;
	int		line_len;
	int		endian;
}				t_image;

typedef struct s_fracal
{
	char	*name;
	void	*mlx_connect;
	void	*mlx_window;
	t_image	image;
	double	escape_value;
	int		iteration_def;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;

void		fract_init(t_fractal *fract);
void		malloc_error(void);
int			ft_strncmp(const char *s1, const char *s2, int n);
void		ft_putstr_fd(char *s, int fd);
double		map(double num, double new_min, double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
void		my_pixel_put(int x, int y, t_image *img, int color);
void		pixel_handle(int x, int y, t_fractal *fract);
void		render(t_fractal *fract);
int			key_handler(int keysym, t_fractal *fract);
int			close_handler(t_fractal *fract);
int			mouse_handler(int button, int x, int y, t_fractal *fract);
void		destroy(t_fractal *fract);
double		float_atoi(char *str);
void		mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fract);
int			julia_track(int x, int y, t_fractal *fract);

#endif
