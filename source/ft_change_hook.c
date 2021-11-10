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
	if (info->flag_right == 1)
		info->data.player.look += M_PI / 90;
	if (info->flag_left == 1)
		info->data.player.look -= M_PI / 90;
}
