/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayousf <cbayousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:39:44 by cbayousf          #+#    #+#             */
/*   Updated: 2025/03/08 16:18:52 by cbayousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	pow_z(t_complex a)
{
	t_complex	z;

	z.re = a.re * a.re - a.im * a.im;
	z.im = 2 * a.re * a.im;
	return (z);
}

t_complex	sum_z(t_complex a, t_complex b)
{
	t_complex	z;

	z.re = a.re + b.re;
	z.im = a.im + b.im;
	return (z);
}

double	ft_scale(double x, double min, double max, double screen_size)
{
	double	range;
	double	scale;

	range = max - min;
	scale = range / screen_size;
	return (min + x * scale);
}

void	put_pixel(int x, int y, int color, t_image *img)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_color(int i, t_fractol fractal)
{
	if (i == fractal.iters)
		return (0x000000);
	else
		return (i * 0x170101);
}
