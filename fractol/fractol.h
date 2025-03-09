/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayousf <cbayousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:55:58 by cbayousf          #+#    #+#             */
/*   Updated: 2025/03/09 13:30:36 by cbayousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

# define HEIGHT 800
# define WIDTH 800

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractol
{
	double	zoom;
	int		iters;
	void	*mlx_ptr;
	void	*mlx_win;
	t_image	img;
	char	*name;
	double	julia_real;
	double	julia_imaginar;
}	t_fractol;

int			ft_strcmp(const char *s1, const char *s2);
double		ft_atoi_double(char *str);
void		error(void);
int			invalide_cord(char *str);
int			close_win(t_fractol *fract);
int			mouse_handler(int button, int x, int y, t_fractol *fract);
int			key_handler(int keycode, t_fractol *fract);
void		julia_handel(char **av, t_fractol *fractol);
double		ft_scale(double x, double min, double max, double screen_size);
void		put_pixel(int x, int y, int color, t_image *img);
int			create_color(int i, t_fractol fractal);
void		colorer_img(t_fractol *fract);
t_complex	pow_z(t_complex a);
t_complex	sum_z(t_complex a, t_complex b);

#endif
