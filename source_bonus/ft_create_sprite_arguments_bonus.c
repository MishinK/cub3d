/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_sprite_arguments.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 22:12:05 by ashea             #+#    #+#             */
/*   Updated: 2020/08/13 22:42:55 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_create_sprite_arguments(t_info *info,
		t_sprite_arguments *arg, int count)
{
	arg->sprite_dir = atan2((info->data.s.sprites[count]).y -
			info->data.player.y, (info->data.s.sprites[count]).x -
			info->data.player.x);
	while (arg->sprite_dir - info->data.player.look > M_PI)
		arg->sprite_dir -= 2 * M_PI;
	while (arg->sprite_dir - info->data.player.look < -M_PI)
		arg->sprite_dir += 2 * M_PI;
	arg->sprite_screen_size = (2000 < (int)(info->data.resolution.y /
				(info->data.s.sprites[count]).dist)) ? 2000 :
		(int)(info->data.resolution.y / (info->data.s.sprites[count]).dist);
	arg->h_offset = (arg->sprite_dir - info->data.player.look) *
		(info->data.resolution.x) / (M_PI / 3) +
		(info->data.resolution.x / 2) - arg->sprite_screen_size / 2;
	arg->v_offset = info->data.resolution.y / 2 -
		arg->sprite_screen_size / 2 + info->look_up;
}

int			ft_hit_or_shot(t_info *info, t_sprite_arguments *arg, int count)
{
	int		x;
	int		y;

	x = ((info->data.s.sprites[count]).x - 32) / 64;
	y = ((info->data.s.sprites[count]).y - 32) / 64;
	if (ft_if_hit(info, x, y, count))
	{
		if (ft_if_head_shot(info, arg))
			return (ft_death_sprite(info, 1, x, y));
		if (ft_if_hit_shot_knife(info, arg))
		{
			if ((info->s_arg[y][x]).life > 0)
				ft_hit_sprite(info, x, y);
			else
				return (ft_death_sprite(info, 0, x, y));
		}
	}
	return (0);
}

int			ft_if_hit(t_info *info, int x, int y, int count)
{
	return (((info->s_arg[y][x]).flag_sprite == 1
				&& info->flag_button == 1)
			&& (info->count_patron > 0 ||
				(info->data.s.sprites[count]).dist * 64 < 50));
}

int			ft_if_head_shot(t_info *info, t_sprite_arguments *arg)
{
	return (info->mouse.x >= arg->h_offset + 2 *
			arg->sprite_screen_size / 5 &&
			info->mouse.x <= arg->h_offset + 3 *
			arg->sprite_screen_size / 5 &&
			info->mouse.y >= arg->v_offset +
			arg->sprite_screen_size / 3 &&
			info->mouse.y <= arg->v_offset +
			arg->sprite_screen_size / 3 +
			arg->sprite_screen_size / 7 &&
			info->count_patron > 0);
}

int			ft_if_hit_shot_knife(t_info *info, t_sprite_arguments *arg)
{
	return (info->mouse.x >= arg->h_offset +
			arg->sprite_screen_size / 3 &&
			info->mouse.x <= arg->h_offset +
			2 * arg->sprite_screen_size / 3 &&
			info->mouse.y >= arg->v_offset +
			arg->sprite_screen_size / 3 &&
			info->mouse.y <= arg->v_offset +
			arg->sprite_screen_size);
}
