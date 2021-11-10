/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_hud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 03:15:17 by ashea             #+#    #+#             */
/*   Updated: 2020/08/13 16:24:11 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_draw_hud(t_info *info)
{
	mlx_string_put(info->mlx.ptr, info->mlx.win,
			11 * info->data.resolution.x / 14, info->data.resolution.y / 6,
			0x00000000, info->patron);
	mlx_put_image_to_window(info->mlx.ptr, info->mlx.win,
			info->img_patron.ptr, 29 * info->data.resolution.x / 30
			- info->img_patron.width, info->img_patron.height);
	mlx_string_put(info->mlx.ptr, info->mlx.win, 9 * info->data.resolution.x
			/ 14, info->data.resolution.y / 6, 0x00000000, info->life);
	mlx_put_image_to_window(info->mlx.ptr, info->mlx.win,
			info->img_life.ptr, 19 * info->data.resolution.x / 20
			- info->img_life.width, info->img_life.height / 4);
}

void		ft_game_over(t_info *info)
{
	int		pid;

	mlx_put_image_to_window(info->mlx.ptr, info->mlx.win,
			info->img_game_over.ptr, 0, 0);
	if (info->flag_game_over == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			system("killall afplay");
			system("afplay ./sound/game_over1.wav");
			system("afplay ./sound/game_over2.wav");
			exit(0);
		}
		info->flag_game_over = 1;
	}
}

void		ft_win_over(t_info *info)
{
	int		pid;

	mlx_put_image_to_window(info->mlx.ptr, info->mlx.win,
			info->img_win_over.ptr, 0, 0);
	if (info->flag_win_over == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			system("afplay ./sound/win_over.wav");
			exit(0);
		}
		info->flag_win_over = 1;
	}
}
