/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:34:24 by ashea             #+#    #+#             */
/*   Updated: 2020/08/12 03:22:29 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_create_info_texture(t_info *info)
{
	info->img_no = ft_create_img(info, info->data.path.no, 64, 64);
	info->img_so = ft_create_img(info, info->data.path.so, 64, 64);
	info->img_we = ft_create_img(info, info->data.path.we, 64, 64);
	info->img_ea = ft_create_img(info, info->data.path.ea, 64, 64);
	info->img_no2 = ft_create_img(info, "./path/north_texture2.xpm", 64, 64);
	info->img_so2 = ft_create_img(info, "./path/south_texture2.xpm", 64, 64);
	info->img_we2 = ft_create_img(info, "./path/west_texture2.xpm", 64, 64);
	info->img_ea2 = ft_create_img(info, "./path/east_texture2.xpm", 64, 64);
	info->img_no3 = ft_create_img(info, "./path/north_texture3.xpm", 64, 64);
	info->img_so3 = ft_create_img(info, "./path/south_texture3.xpm", 64, 64);
	info->img_we3 = ft_create_img(info, "./path/west_texture3.xpm", 64, 64);
	info->img_ea3 = ft_create_img(info, "./path/east_texture3.xpm", 64, 64);
	info->img_no_d = ft_create_img(info, "./path/north_texture_d.xpm", 64, 64);
	info->img_so_d = ft_create_img(info, "./path/south_texture_d.xpm", 64, 64);
	info->img_we_d = ft_create_img(info, "./path/west_texture_d.xpm", 64, 64);
	info->img_ea_d = ft_create_img(info, "./path/east_texture_d.xpm", 64, 64);
	info->img_floor = ft_create_img(info, "./path/floor_texture.xpm", 64, 64);
	info->img_sky = ft_create_img(info, "./path/sky_texture.xpm",
			5 * info->data.resolution.x, info->data.resolution.y);
}

void		ft_create_info_sprite(t_info *info)
{
	info->img_s = ft_create_img(info, info->data.path.s, 124, 124);
	info->img_s2 = ft_create_img(info, "./path/sprite_texture2.xpm", 124, 124);
	info->img_s3 = ft_create_img(info, "./path/sprite_texture3.xpm", 124, 124);
	info->img_treasure = ft_create_img(info, "./path/treasure.xpm", 156, 156);
	info->img_treasure2 = ft_create_img(info, "./path/treasure2.xpm", 156, 156);
	ft_create_s_arg(info);
	info->count_sprites = info->data.s.count;
}

void		ft_create_info_hud(t_info *info)
{
	int		x;
	int		y;

	x = info->data.resolution.x;
	y = info->data.resolution.y;
	info->img_gun = ft_create_img(info, "./path/gun.xpm", x / 2, 2 * y / 3);
	info->img_gun2 = ft_create_img(info, "./path/gun2.xpm", x / 2, 2 * y / 3);
	info->img_gun3 = ft_create_img(info, "./path/gun3.xpm", x / 2, 2 * y / 3);
	info->img_gun4 = ft_create_img(info, "./path/gun4.xpm", x / 2, 2 * y / 3);
	info->img_gun5 = ft_create_img(info, "./path/gun5.xpm", x / 2, 2 * y / 3);
	info->img_knife = ft_create_img(info, "./path/k.xpm", x / 2, 2 * y / 3);
	info->img_knife2 = ft_create_img(info, "./path/k2.xpm", x / 2, 2 * y / 3);
	info->img_knife3 = ft_create_img(info, "./path/k3.xpm", x / 2, 2 * y / 3);
	info->img_knife4 = ft_create_img(info, "./path/k4.xpm", x / 2, 2 * y / 3);
	info->img_knife5 = ft_create_img(info, "./path/k5.xpm", x / 2, 2 * y / 3);
	info->img_game_over = ft_create_img(info, "./path/game_over.xpm", x, y);
	info->img_win_over = ft_create_img(info, "./path/win_over.xpm", x, y);
	info->img_instruction = ft_create_img(info, "./path/instruction.xpm", x, y);
	info->img_aim = ft_create_img(info, "./path/aim.xpm", x / 10, y / 8);
	info->img_patron = ft_create_img(info, "./path/patron.xpm", x / 15, y / 10);
	info->img_life = ft_create_img(info, "./path/life.xpm", x / 3, y / 15);
	info->count_patron = 15;
	info->count_life = 100;
	ft_patron_bar(info);
	ft_life_bar(info);
}

void		ft_create_info_flag(t_info *info)
{
	info->flag_win_over = 0;
	info->flag_game_over = 0;
	info->flag_squat = 0;
	info->look_up = 0;
	info->flag_up = 0;
	info->flag_down = 0;
	info->flag_up_mouse = 0;
	info->flag_down_mouse = 0;
	info->flag_right = 0;
	info->flag_left = 0;
	info->flag_right_mouse = 0;
	info->flag_left_mouse = 0;
	info->flag_w = 0;
	info->flag_s = 0;
	info->flag_a = 0;
	info->flag_d = 0;
	info->flag_mini = 0;
	info->time_gun = 0;
	info->flag_instruction = 1;
}

void		ft_create_info(t_info *info)
{
	t_mlx	mlx;
	int		sizex;
	int		sizey;

	if (info->flag_lvl == 0)
	{
		if (!(info->mlx.ptr = mlx_init()))
			ft_stop_all("mlx ptr", info);
		mlx_get_screen_size(mlx.ptr, &sizex, &sizey);
		if (info->data.resolution.x > sizex)
			info->data.resolution.x = sizex;
		if (info->data.resolution.y > sizey)
			info->data.resolution.y = sizey;
		if (!(info->mlx.win = mlx_new_window(info->mlx.ptr,
						info->data.resolution.x, info->data.resolution.y,
						"THIS IS SPARTA!!!")))
			ft_stop_all("win ptr", info);
	}
	info->img_win = ft_create_img_win(info);
	ft_create_info_texture(info);
	ft_create_info_sprite(info);
	ft_create_info_hud(info);
	ft_create_info_flag(info);
}
