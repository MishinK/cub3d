/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_distance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:37:17 by ashea             #+#    #+#             */
/*   Updated: 2020/08/12 04:53:40 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_look_up(float f)
{
	while (f > 2 * M_PI)
		f -= 2 * M_PI;
	while (f < 0)
		f += 2 * M_PI;
	if (f > 0 && f < M_PI)
		return (1);
	if (f == 0 || f == M_PI)
		return (0);
	return (-1);
}

int				ft_look_right(float f)
{
	while (f > 2 * M_PI)
		f -= 2 * M_PI;
	while (f < 0)
		f += 2 * M_PI;
	if (f < M_PI / 2 || f > 3 * M_PI / 2)
		return (1);
	if (f == M_PI / 2 || f == 3 * M_PI / 2)
		return (0);
	return (-1);
}

t_distance		ft_create_distance(t_info *info, int i)
{
	float		f;
	t_distance	cv;
	t_distance	ch;

	f = (i - info->data.resolution.x / 2) * (M_PI / 3)
		/ (info->data.resolution.x + 0.0);
	cv = ft_vertical_tracing(info, info->data.player.look + f);
	ch = ft_horizontal_tracing(info, info->data.player.look + f);
	if (cv.distance < ch.distance)
	{
		cv.h = (int)(info->data.resolution.y * 64) / (cv.distance * cos(f));
		return (cv);
	}
	ch.h = (int)(info->data.resolution.y * 64) / (ch.distance * cos(f));
	return (ch);
}

t_distance		ft_vertical_tracing(t_info *info, float angle)
{
	t_ray		ray;

	if (ft_look_right(angle) == 0)
		return ((t_distance){1000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
	ray.x = (int)((info->data.player.x / 64) * 64)
		+ ((ft_look_right(angle) == 1) ? 64 : (-0.0001));
	ray.y = info->data.player.y
		+ (info->data.player.x - ray.x) * tan(angle) * (-1);
	ray.delta_x = (ft_look_right(angle) == 1) ? 64 : -64;
	ray.delta_y = ray.delta_x * tan(angle);
	ray.angle = angle;
	ray.flag_vert = 1;
	return (ft_search_wall(info, &ray));
}

t_distance		ft_horizontal_tracing(t_info *info, float angle)
{
	t_ray		ray;

	if (ft_look_up(angle) == 0)
		return ((t_distance){1000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
	ray.y = (int)((info->data.player.y / 64) * 64)
		+ ((ft_look_up(angle) == 1) ? 64 : (-0.0001));
	ray.x = info->data.player.x
		+ (info->data.player.y - ray.y) / tan(angle) * (-1);
	ray.delta_y = (ft_look_up(angle) == 1) ? 64 : -64;
	ray.delta_x = ray.delta_y / tan(angle);
	ray.angle = angle;
	ray.flag_vert = 0;
	return (ft_search_wall(info, &ray));
}
