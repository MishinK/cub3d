/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 01:34:59 by ashea             #+#    #+#             */
/*   Updated: 2020/08/12 02:13:04 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_change_position(t_info *info, int change_x, int change_y)
{
	if (!(info->data.map.content[(info->data.player.y + change_y * 3)
				/ 64][info->data.player.x / 64] == '1' ||
				info->data.map.content[(info->data.player.y + change_y)
				/ 64][info->data.player.x / 64] == '2'))
		info->data.player.y += change_y;
	if (!(info->data.map.content[info->data.player.y
				/ 64][(info->data.player.x + change_x * 3) / 64] == '1' ||
				info->data.map.content[info->data.player.y
				/ 64][(info->data.player.x + change_x) / 64] == '2'))
		info->data.player.x += change_x;
	ft_find_sprite(info);
}
