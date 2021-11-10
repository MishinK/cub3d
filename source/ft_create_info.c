/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:34:24 by ashea             #+#    #+#             */
/*   Updated: 2020/08/14 00:59:50 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_create_info_texture(t_info *info)
{
	info->img_no = ft_create_img(info, info->data.path.no, 64, 64);
	info->img_so = ft_create_img(info, info->data.path.so, 64, 64);
	info->img_we = ft_create_img(info, info->data.path.we, 64, 64);
	info->img_ea = ft_create_img(info, info->data.path.ea, 64, 64);
}

void		ft_create_info_sprite(t_info *info)
{
	info->img_s = ft_create_img(info, info->data.path.s, 64, 64);
	info->count_sprites = info->data.s.count;
}

void		ft_create_info_flag(t_info *info)
{
	info->flag_right = 0;
	info->flag_left = 0;
	info->flag_w = 0;
	info->flag_s = 0;
	info->flag_a = 0;
	info->flag_d = 0;
}

void		ft_create_info(t_info *info)
{
	t_mlx	mlx;
	int		sizex;
	int		sizey;

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
	info->img_win = ft_create_img_win(info);
	ft_create_info_texture(info);
	ft_create_info_sprite(info);
	ft_create_info_flag(info);
}
