/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_floor_ceilling.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 03:10:54 by ashea             #+#    #+#             */
/*   Updated: 2020/08/13 15:33:11 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_color_floor_dop(t_distance *distance,
		float *floorxwall, float *floorywall)
{
	float	dx;
	float	dy;
	float	wallx;

	dx = (distance->flag_door == 1) ? distance->x_d : distance->x;
	dy = (distance->flag_door == 1) ? distance->y_d : distance->y;
	wallx = (distance->flag_door == 1) ? distance->hit_d : distance->hit;
	if (distance->vertical == 0)
		*floorxwall = dx + wallx;
	else
		*floorxwall = dx + ((ft_look_right(distance->angle) == 1) ? 0.0 : 1.0);
	if (distance->vertical == 1)
		*floorywall = dy + wallx;
	else
		*floorywall = dy + ((ft_look_up(distance->angle) == 1) ? 0.0 : 1.0);
}

int			ft_color_floor(t_info *info, t_distance *distance, int y)
{
	float	f[6];
	int		tex_x;
	int		tex_y;

	ft_color_floor_dop(distance, &f[0], &f[1]);
	f[2] = ((float)info->data.resolution.y) / (2 * (float)(y -
				info->look_up) - (float)info->data.resolution.y);
	f[3] = (distance->flag_door == 1) ? (f[2]) /
		((float)distance->distance_d / 64) : (f[2]) /
		((float)distance->distance / 64);
	f[4] = f[3] * (float)f[0] + (1.0 - f[3]) *
		(((float)(info->data.player.x)) / 64);
	f[5] = f[3] * (float)f[1] + (1.0 - f[3]) *
		(((float)(info->data.player.y)) / 64);
	tex_x = (int)(f[4] * 64) % 64;
	tex_y = (int)(f[5] * 64) % 64;
	return (info->img_floor.addr[tex_y
			* info->img_floor.size_line / 4 + tex_x]);
}

int			ft_color_ceilling(t_info *info, t_distance *distance, int i, int j)
{
	int		pos;

	pos = j % info->img_sky.height * info->img_sky.size_line / 4
		+ (int)(i + info->data.player.look * 500) % info->img_sky.width;
	while (info->img_sky.addr[pos] == 0x00000000)
	{
		pos = j % info->img_sky.height * info->img_sky.size_line / 4 +
			(int)(i + info->data.player.look * 500) % info->img_sky.width;
		i++;
	}
	return (info->img_sky.addr[pos]);
}
