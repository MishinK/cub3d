/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:36:01 by ashea             #+#    #+#             */
/*   Updated: 2020/08/13 15:42:54 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_draw_wall_sprite(t_info *info)
{
	int			i;
	int			limit[2];
	t_distance	dist[info->data.resolution.x];

	i = 0;
	while (i < info->data.resolution.x)
	{
		dist[i] = ft_create_distance(info, i);
		limit[0] = (info->data.resolution.y -
				(dist[i]).h) * 0.5 + info->look_up;
		limit[1] = (info->data.resolution.y +
				(dist[i]).h) * 0.5 + info->look_up;
		ft_paint_map_dop(info, limit, dist[i], i);
		i++;
	}
	ft_draw_sprite(info, dist);
}

int				ft_paint_map(t_info *info)
{
	mlx_put_image_to_window(info->mlx.ptr,
			info->mlx.win, info->img_win.ptr, 0, 0);
	ft_mouse_hook(info);
	ft_change_position_hook(info);
	ft_change_look_vertical_hook(info);
	ft_change_look_horizontal_hook(info);
	ft_draw_wall_sprite(info);
	if (info->flag_mini == 1)
		ft_create_map_pixel_mini(info);
	if (info->count_patron > 0)
		ft_draw_gun(info);
	else
		ft_draw_knife(info);
	ft_draw_hud(info);
	if (info->count_life <= 0)
		ft_game_over(info);
	if (info->count_sprites == 0)
		ft_win_over(info);
	if (info->flag_instruction == 1)
		mlx_put_image_to_window(info->mlx.ptr, info->mlx.win,
				info->img_instruction.ptr, 0, 0);
	return (0);
}

void			ft_paint_map_dop(t_info *info, int *limit,
		t_distance distance, int i)
{
	int			j;
	int			pos;

	j = 0;
	while (j < info->data.resolution.y)
	{
		pos = j * info->img_win.size_line / 4 + i;
		if (j <= limit[0])
			info->img_win.addr[pos] = ft_color_ceilling(info, &distance, i, j);
		else if (j > limit[0] && j < limit[1])
			info->img_win.addr[pos] =
				ft_color_walls(info, j - limit[0], &distance);
		else if (j >= limit[1])
			info->img_win.addr[pos] = ft_color_floor(info, &distance, j);
		j++;
	}
}
