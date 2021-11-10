/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 04:34:12 by ashea             #+#    #+#             */
/*   Updated: 2020/08/12 04:34:41 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_distance		ft_search_wall(t_info *info, t_ray *ray)
{
	t_distance	dist;
	int			map_x;
	int			map_y;

	dist = (t_distance){1000000, 0, 0, ray->angle, ray->flag_vert,
		0, 0, 0, 0, 0, 0, 0};
	while (ray->x >= 0 && ray->y >= 0 && (ray->x / 64)
			< info->data.map.x && (ray->y / 64) < info->data.map.y)
	{
		map_x = (ray->x / 64);
		map_y = (ray->y / 64);
		if ((info->data.map.content)[map_y][map_x] == '1')
		{
			dist.distance = sqrt(pow((info->data.player.x - ray->x), 2)
					+ pow((info->data.player.y - ray->y), 2));
			break ;
		}
		ray->x += ray->delta_x;
		ray->y += ray->delta_y;
	}
	ft_search_wall_dop(info, ray, &dist);
	return (dist);
}

void			ft_search_wall_dop(t_info *info, t_ray *ray, t_distance *dist)
{
	dist->x = (ray->x / 64);
	dist->y = (ray->y / 64);
	ray->x = (ray->flag_vert == 1) ? fabs(ray->y) : fabs(ray->x);
	dist->hit = (float)(ray->x / 64) - (int)(ray->x / 64);
}
