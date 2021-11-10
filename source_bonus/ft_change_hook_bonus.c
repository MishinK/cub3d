/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 03:13:29 by ashea             #+#    #+#             */
/*   Updated: 2020/08/13 15:52:53 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_mouse_hook(t_info *info)
{
	mlx_mouse_get_pos(info->mlx.win, &(info->mouse.x), &(info->mouse.y));
	if (info->mouse.x < info->data.resolution.x && info->mouse.x >= 0
			&& info->mouse.y < info->data.resolution.y && info->mouse.y >= 0)
		mlx_mouse_hide();
	else
		mlx_mouse_show();
	info->flag_right_mouse = (info->mouse.x >= 9
			* info->data.resolution.x / 10) ? 1 : 0;
	info->flag_left_mouse = (info->mouse.x <=
			info->data.resolution.x / 10) ? 1 : 0;
	info->flag_down_mouse = (info->mouse.y >= 9
			* info->data.resolution.y / 10) ? 1 : 0;
	info->flag_up_mouse = (info->mouse.y <=
			info->data.resolution.y / 10) ? 1 : 0;
	mlx_put_image_to_window(info->mlx.ptr, info->mlx.win,
			info->img_aim.ptr, info->mouse.x - info->img_aim.width / 2,
			info->mouse.y - 2 * info->img_aim.height / 3);
}

void		ft_change_position_hook(t_info *info)
{
	if (info->flag_w == 1)
		ft_change_position(info, -sin(info->data.player.look - M_PI / 2)
				* 6, cos(info->data.player.look - M_PI / 2) * 6);
	if (info->flag_s == 1)
		ft_change_position(info, sin(info->data.player.look - M_PI / 2)
				* 6, -cos(info->data.player.look - M_PI / 2) * 6);
	if (info->flag_a == 1)
		ft_change_position(info, sin(info->data.player.look) * 6,
				-cos(info->data.player.look) * 6);
	if (info->flag_d == 1)
		ft_change_position(info, -sin(info->data.player.look) * 6,
				+cos(info->data.player.look) * 6);
}

void		ft_change_look_vertical_hook(t_info *info)
{
	if (info->flag_right == 1 || info->flag_right_mouse == 1)
		info->data.player.look += M_PI / 90;
	if (info->flag_left == 1 || info->flag_left_mouse == 1)
		info->data.player.look -= M_PI / 90;
}

void		ft_change_look_horizontal_hook(t_info *info)
{
	if (info->flag_down == 1 || info->flag_down_mouse == 1)
	{
		info->look_up -= info->data.resolution.y / 20;
		if (info->look_up < -info->data.resolution.y / 2)
			info->look_up = -info->data.resolution.y / 2;
	}
	if (info->flag_up == 1 || info->flag_up_mouse == 1)
	{
		info->look_up += info->data.resolution.y / 20;
		if (info->look_up > info->data.resolution.y / 2)
			info->look_up = info->data.resolution.y / 2;
	}
}
