/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayousf <cbayousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:00:36 by cbayousf          #+#    #+#             */
/*   Updated: 2025/03/09 12:33:03 by cbayousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	initialisation(t_fractol *fract)
{
	fract->mlx_ptr = mlx_init();
	if (!fract->mlx_ptr)
		exit(1);
	fract->mlx_win = mlx_new_window(fract->mlx_ptr, 800, 800, fract->name);
	if (!fract->mlx_win)
		exit(1);
	fract->img.img_ptr = mlx_new_image(fract->mlx_ptr, 800, 800);
	if (!fract->img.img_ptr)
	{
		mlx_destroy_window(fract->mlx_ptr, fract->mlx_win);
		exit(1);
	}
	fract->img.addr = mlx_get_data_addr(fract->img.img_ptr,
			&fract->img.bits_per_pixel, &fract->img.size_line,
			&fract->img.endian);
	if (!fract->img.addr)
		exit(1);
	fract->zoom = 1.0;
	fract->iters = 240;
}

static void	c_value(t_complex *z, t_complex *c, t_fractol *fract)
{
	if (!ft_strcmp(fract->name, "mandelbrot"))
	{
		c->re = z->re;
		c->im = z->im;
	}
	else
	{
		c->re = fract->julia_real;
		c->im = fract->julia_imaginar;
	}
}

static void	colorer_pixel(int x, int y, t_fractol *fract)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.re = ft_scale(x, -2, 2, HEIGHT) * fract->zoom;
	z.im = ft_scale(y, 2, -2, HEIGHT) * fract->zoom;
	c_value(&z, &c, fract);
	while (i < fract->iters)
	{
		z = sum_z(pow_z(z), c);
		if ((z.re * z.re + z.im * z.im) > 4)
		{
			color = create_color(i, *fract);
			put_pixel(x, y, color, &fract->img);
			return ;
		}
		i++;
	}
	color = create_color(i, *fract);
	put_pixel(x, y, color, &fract->img);
}

void	colorer_img(t_fractol *fract)
{
	double	i;
	double	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			colorer_pixel(i, j, fract);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fract->mlx_ptr,
		fract->mlx_win, fract->img.img_ptr, 0, 0);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		|| (ac == 4 && !ft_strcmp(av[1], "julia")))
	{
		julia_handel(av, &fractol);
		fractol.name = av[1];
		initialisation(&fractol);
		colorer_img(&fractol);
		mlx_key_hook(fractol.mlx_win, key_handler, &fractol);
		mlx_mouse_hook(fractol.mlx_win, mouse_handler, &fractol);
		mlx_hook(fractol.mlx_win, 17, 0, close_win, &fractol);
		mlx_loop(fractol.mlx_ptr);
	}
	else
	{
		error();
		exit(1);
	}
	exit(0);
}
