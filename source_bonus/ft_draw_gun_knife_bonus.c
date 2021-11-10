/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_gun_knife.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 03:14:28 by ashea             #+#    #+#             */
/*   Updated: 2020/08/13 16:15:19 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_draw_gun(t_info *info)
{
	int		x[2];

	x[0] = info->data.resolution.x / 2 - info->img_gun.width / 2;
	x[1] = info->data.resolution.y - info->img_gun.height;
	if (info->time_gun == 0)
		mlx_put_image_to_window(info->mlx.ptr, info->mlx.win,
				info->img_gun.ptr, x[0], x[1]);
	else
	{
		info->time_gun++;
		if (info->time_gun > 0 && info->time_gun < 5)
			mlx_put_image_to_window(info->mlx.ptr, info->mlx.win,
					info->img_gun2.ptr, x[0], x[1]);
		else if (info->time_gun >= 5 && info->time_gun < 10)
			mlx_put_image_to_window(info->mlx.ptr, info->mlx.win,
					info->img_gun3.ptr, x[0], x[1]);
		else if (info->time_gun >= 10 && info->time_gun < 15)
			mlx_put_image_to_window(info->mlx.ptr, info->mlx.win,
					info->img_gun4.ptr, x[0], x[1]);
		else if (info->time_gun >= 15 && info->time_gun < 20)
			mlx_put_image_to_window(info->mlx.ptr, info->mlx.win,
					info->img_gun5.ptr, x[0], x[1]);
		else
			info->time_gun = 0;
	}
}

void		ft_draw_knife(t_info *info)
{
	int		x[2];

	x[0] = info->data.resolution.x / 2 - info->img_knife.width / 2;
	x[1] = info->data.resolution.y - info->img_knife.height;
	if (info->time_gun == 0)
		mlx_put_image_to_window(info->mlx.ptr, info->mlx.win,
				info->img_knife.ptr, x[0], x[1]);
	else
	{
		info->time_gun++;
		if (info->time_gun > 0 && info->time_gun < 5)
			mlx_put_image_to_window(info->mlx.ptr, info->mlx.win,
					info->img_knife2.ptr, x[0], x[1]);
		else if (info->time_gun >= 5 && info->time_gun < 10)
			mlx_put_image_to_window(info->mlx.ptr, info->mlx.win,
					info->img_knife3.ptr, x[0], x[1]);
		else if (info->time_gun >= 10 && info->time_gun < 15)
			mlx_put_image_to_window(info->mlx.ptr, info->mlx.win,
					info->img_knife4.ptr, x[0], x[1]);
		else if (info->time_gun >= 15 && info->time_gun < 20)
			mlx_put_image_to_window(info->mlx.ptr, info->mlx.win,
					info->img_knife5.ptr, x[0], x[1]);
		else
			info->time_gun = 0;
	}
}
