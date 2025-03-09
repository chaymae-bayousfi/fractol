/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayousf <cbayousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:53:48 by cbayousf          #+#    #+#             */
/*   Updated: 2025/03/09 11:39:41 by cbayousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static double	ft_avant(char **str)
{
	double	r;

	r = 0;
	while (**str && **str != '.')
	{
		r = r * 10 + (**str - '0');
		(*str)++;
	}
	return (r);
}

static double	ft_apres(char *str)
{
	double	k;
	double	r;

	k = 1;
	r = 0;
	if (*str == '.')
		str++;
	while (*str)
	{
		k = k / 10;
		r = r + (*str - '0') * k;
		str++;
	}
	return (r);
}

double	ft_atoi_double(char *str)
{
	double	first;
	double	seconde;
	int		signe;
	int		i;

	i = 0;
	signe = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	first = ft_avant(&str);
	seconde = ft_apres(str);
	return ((first + seconde) * signe);
}

void	error(void)
{
	write(1, "\n\tInvalid Input :?\n\n\
	> ./fractol mandelbrott\n\
	> ./fractol julia < re > < im > ( re/im in [-2,2] )\n\n", 96);
}
