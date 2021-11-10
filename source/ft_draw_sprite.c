/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:15:35 by ashea             #+#    #+#             */
/*   Updated: 2020/08/05 21:19:00 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void					ft_draw_sprite(t_info *info, t_distance *dist)
{
	int					count;
	t_sprite_arguments	arg;

	count = info->data.s.count;
	while (count > 0)
	{
		count--;
		arg.sprite_dir = atan2((info->data.s.sprites[count]).y -
				info->data.player.y, (info->data.s.sprites[count]).x -
				info->data.player.x);
		while (arg.sprite_dir - info->data.player.look > M_PI)
			arg.sprite_dir -= 2 * M_PI;
		while (arg.sprite_dir - info->data.player.look < -M_PI)
			arg.sprite_dir += 2 * M_PI;
		arg.sprite_screen_size = (2000 < (int)(info->data.resolution.y /
					(info->data.s.sprites[count]).dist)) ? 2000 :
			(int)(info->data.resolution.y / (info->data.s.sprites[count]).dist);
		arg.h_offset = (arg.sprite_dir - info->data.player.look) *
			(info->data.resolution.x) / (M_PI / 3) +
			(info->data.resolution.x / 2) - arg.sprite_screen_size / 2;
		arg.v_offset = info->data.resolution.y / 2 - arg.sprite_screen_size / 2;
		ft_draw_sprite_dop(info, dist, &arg, count);
	}
}

void					ft_draw_sprite_dop(t_info *info, t_distance *dist,
		t_sprite_arguments *arg, int count)
{
	int					i[3];

	i[2] = count;
	i[0] = 0;
	while (i[0] < arg->sprite_screen_size)
	{
		if (arg->h_offset + i[0] >= 0 &&
				arg->h_offset + i[0] < info->data.resolution.x)
		{
			i[1] = 0;
			while (i[1] < arg->sprite_screen_size)
			{
				if (arg->v_offset + i[1] >= 0 &&
						arg->v_offset + i[1] < info->data.resolution.y)
					ft_draw_sprite_dop_dop(info, dist, arg, i);
				i[1]++;
			}
		}
		i[0]++;
	}
}

void					ft_draw_sprite_dop_dop(t_info *info, t_distance *dist,
		t_sprite_arguments *arg, int *i)
{
	int					pos2;
	int					pos;

	pos = ((arg->v_offset + i[1])) *
		info->img_win.size_line / 4 + (arg->h_offset + i[0]);
	pos2 = (i[1] * 64) / arg->sprite_screen_size *
		info->img_s.size_line / 4 + (i[0] * 64) / arg->sprite_screen_size;
	if ((dist[arg->h_offset + i[0]]).distance >
			(info->data.s.sprites[i[2]]).dist * 64)
		if (info->img_s.addr[pos2] != info->img_s.addr[0])
			info->img_win.addr[pos] = info->img_s.addr[pos2];
}
