/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:15:35 by ashea             #+#    #+#             */
/*   Updated: 2020/08/13 23:29:35 by ashea            ###   ########.fr       */
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
		ft_create_sprite_arguments(info, &arg, count);
		if (ft_hit_or_shot(info, &arg, count))
			break ;
		ft_draw_sprite_dop(info, dist, &arg, count);
	}
}

void					ft_draw_sprite_dop(t_info *info, t_distance *dist,
		t_sprite_arguments *arg, int count)
{
	int					i[7];

	i[2] = count;
	i[3] = ((info->data.s.sprites[count]).x - 32) / 64;
	i[4] = ((info->data.s.sprites[count]).y - 32) / 64;
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
	i[5] = ((arg->v_offset + i[1])) *
		info->img_win.size_line / 4 + (arg->h_offset + i[0]);
	if ((info->s_arg[i[4]][i[3]]).flag_sprite == 1)
		i[6] = (i[1] * info->img_s.width) / arg->sprite_screen_size *
			(info->img_s.size_line / 4) + (i[0] * info->img_s.height)
			/ arg->sprite_screen_size;
	else
		i[6] = (i[1] * info->img_treasure.width) / arg->sprite_screen_size *
			(info->img_treasure.size_line / 4) +
			(i[0] * info->img_treasure.height) / arg->sprite_screen_size;
	if ((info->s_arg[i[4]][i[3]]).flag_sprite == 1)
		if (ft_if_closer_walls(info, dist, arg, i))
			ft_drow_enemy(info, dist, arg, i);
	if ((info->s_arg[i[4]][i[3]]).flag_sprite == 0)
		if (ft_if_closer_walls(info, dist, arg, i))
			ft_drow_treasures(info, dist, arg, i);
}
