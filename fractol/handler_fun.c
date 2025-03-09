/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayousf <cbayousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:19:47 by cbayousf          #+#    #+#             */
/*   Updated: 2025/03/09 11:22:28 by cbayousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	invalide_cord(char *str )
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] != '.' && (str[i] < '0' || str[i] > '9'))
			return (1);
		if (str[i] == '.')
			count++;
		if (str[i] == '.' && !str[i + 1])
			return (1);
		i++;
	}
	if (count > 1)
		return (1);
	return (0);
}

int	close_win(t_fractol *fract)
{
	mlx_destroy_image(fract->mlx_ptr, fract->img.img_ptr);
	mlx_destroy_window(fract->mlx_ptr, fract->mlx_win);
	exit (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *fract)
{
	(void)x;
	(void)y;
	if (button == 4)
		fract->zoom *= 1.1;
	else if (button == 5)
		fract->zoom /= 1.1;
	else
		return (0);
	colorer_img(fract);
	return (0);
}

int	key_handler(int keycode, t_fractol *fract)
{
	if (keycode == 53)
	{
		close_win(fract);
		exit(0);
	}
	return (0);
}

void	julia_handel(char **av, t_fractol *fractol)
{
	if (!ft_strcmp(av[1], "julia"))
	{
		if (invalide_cord(av[2]) || invalide_cord(av[3]))
		{
			error();
			exit(1);
		}
		fractol->julia_real = ft_atoi_double(av[2]);
		fractol->julia_imaginar = ft_atoi_double(av[3]);
		if ((fractol->julia_real > 2 || fractol->julia_real < -2)
			|| (fractol->julia_imaginar > 2 || fractol->julia_imaginar < -2))
		{
			error();
			exit(1);
		}
	}
}
