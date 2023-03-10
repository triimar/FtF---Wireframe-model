/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:54:29 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/24 19:24:49 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_initiate(t_map *s_map)
{
	s_map->window = mlx_init(WIDTH, HEIGHT, "FDF Wireframe Model", true);
	if (!s_map->window)
	{
		error_msg(3);
		exit(EXIT_FAILURE);
	}
	s_map->img = mlx_new_image(s_map->window, WIDTH, HEIGHT);
	if (!s_map->img)
	{
		error_msg(3);
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window(s_map->window, s_map->img, 0, 0) < 0)
	{
		error_msg(3);
		exit(EXIT_FAILURE);
	}
	s_map->y_max = 0;
	s_map->x_max = 0;
	s_map->y_coeff = 1;
	s_map->z_sc = 1;
	s_map->pt_z_max = NULL;
	s_map->pt_z_min = NULL;
	s_map->mtrx = NULL;
}

static double	abs_bigger(double a, double b)
{
	if (fabs(a) >= fabs(b))
		return (a);
	else
		return (b);
}

//taking 4 points of interest - 
// the points of max y and min x &  max y and min x decide the scale on 
// the 2d x axis (width of the window)
// the point of maximum x and y and pont of maximum z value give the
// needed scaling of the 2d y axis (height of the window)
double	default_scale(t_map *s_map)
{
	double	pt_max_z;
	double	max_h;
	double	width_sc;

	if (s_map->x_max >= s_map->y_max)
		width_sc = (WIDTH / 3) / (s_map->x_max - 1) * cos(M_PI / 6);
	else
		width_sc = (WIDTH / 3) / (-1 - s_map->y_max) * cos(M_PI / 6);
	max_h = (s_map->x_max + s_map->y_max - 2) * sin(M_PI / 6) - \
	s_map->mtrx[s_map->y_max - 1][s_map->x_max - 1].pt_z;
	if ((fabs(s_map->pt_z_max->pt_z) >= fabs(s_map->pt_z_min->pt_z)))
		pt_max_z = (s_map->pt_z_max->pt_x + s_map->pt_z_max->pt_y) \
		* sin(M_PI / 6) - fabs(s_map->pt_z_max->pt_z);
	else
		pt_max_z = (s_map->pt_z_min->pt_x + s_map->pt_z_min->pt_y) \
		* sin(M_PI / 6) - fabs(s_map->pt_z_min->pt_z);
	max_h = abs_bigger(max_h, pt_max_z);
	s_map->sc = (HEIGHT / 3) / max_h;
	if (fabs(width_sc) < fabs(s_map->sc))
		s_map->sc = width_sc;
	if (s_map->sc < 1 && s_map->sc >= 0)
		s_map->sc = 1;
	if (s_map->sc < 0)
		s_map->sc = -1 * s_map->sc;
	return (round(s_map->sc));
}

void	ft_defaults(t_map *s_map)
{
	s_map->center.x_0 = WIDTH / 2;
	s_map->center.y_0 = HEIGHT / 2;
	s_map->z_sc = 1;
	s_map->s_rot.x_angle = 0;
	s_map->s_rot.y_angle = 0;
	s_map->s_rot.z_angle = 0;
	default_scale(s_map);
}
