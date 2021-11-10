/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drow_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 22:09:59 by ashea             #+#    #+#             */
/*   Updated: 2020/08/13 23:18:57 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_drow_enemy(t_info *info, t_distance *dist,
		t_sprite_arguments *arg, int *i)
{
	if (ft_if_long_away(info, i, 1))
		info->img_win.addr[i[5]] = (info->img_s.addr[i[6]] !=
				info->img_s.addr[0]) ?
			info->img_s.addr[i[6]] : info->img_win.addr[i[5]];
	else
	{
		if ((info->s_arg[i[4]][i[3]]).time % 1500000 < 750000)
			info->img_win.addr[i[5]] = (info->img_s3.addr[i[6]] !=
					info->img_s3.addr[0]) ?
				info->img_s3.addr[i[6]] : info->img_win.addr[i[5]];
		else
			info->img_win.addr[i[5]] = (info->img_s2.addr[i[6]] !=
					info->img_s2.addr[0]) ?
				info->img_s2.addr[i[6]] : info->img_win.addr[i[5]];
		if ((info->s_arg[i[4]][i[3]]).flag_achtung == 0)
			ft_achtung_sprite(info, i);
		else
		{
			if ((info->s_arg[i[4]][i[3]]).time % 1500000 == 0)
				ft_shot_sprite(info, i);
			else
				(info->s_arg[i[4]][i[3]]).time++;
		}
	}
}

int			ft_if_closer_walls(t_info *info, t_distance *dist,
		t_sprite_arguments *arg, int *i)
{
	return ((dist[arg->h_offset + i[0]]).distance >
			(info->data.s.sprites[i[2]]).dist * 64);
}

void		ft_achtung_sprite(t_info *info, int *i)
{
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		system("afplay ./sound/achtung.wav");
		exit(0);
	}
	(info->s_arg[i[4]][i[3]]).flag_achtung = 1;
}

void		ft_shot_sprite(t_info *info, int *i)
{
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		if (info->count_life > 0)
			system("afplay ./sound/shot.wav");
		exit(0);
	}
	(info->s_arg[i[4]][i[3]]).patron--;
	info->count_life -= 1;
	ft_life_bar(info);
	(info->s_arg[i[4]][i[3]]).time = 1;
}
