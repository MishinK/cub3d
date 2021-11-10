/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drow_treasures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 22:06:20 by ashea             #+#    #+#             */
/*   Updated: 2020/08/13 23:46:55 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_drow_treasures(t_info *info, t_distance *dist,
		t_sprite_arguments *arg, int *i)
{
	if (ft_if_long_away(info, i, 0))
		info->img_win.addr[i[5]] = (info->img_treasure.addr[i[6]] !=
				info->img_treasure.addr[0]) ?
			info->img_treasure.addr[i[6]] : info->img_win.addr[i[5]];
	else
		ft_сollecting_treasures(info, i);
}

int			ft_if_long_away(t_info *info, int *i, int flag_sprite)
{
	if (flag_sprite)
	{
		return ((info->data.s.sprites[i[2]]).dist * 64 > 200
				&& (info->s_arg[i[4]][i[3]]).flag_achtung == 0);
	}
	return ((info->data.s.sprites[i[2]]).dist * 64 > 60
			&& (info->s_arg[i[4]][i[3]]).flag_achtung == 0);
}

void		ft_сollecting_treasures(t_info *info, int *i)
{
	int		pid;

	(info->s_arg[i[4]][i[3]]).flag_achtung = 1;
	if (info->img_treasure2.addr[i[6]] != info->img_treasure2.addr[0])
		info->img_win.addr[i[5]] = info->img_treasure2.addr[i[6]];
	if ((info->s_arg[i[4]][i[3]]).life == 2)
	{
		(info->s_arg[i[4]][i[3]]).life = 0;
		info->count_sprites--;
		pid = fork();
		if (pid == 0)
		{
			system("afplay ./sound/money.wav");
			exit(0);
		}
		info->count_life += 10;
		info->img_life = ft_create_img(info, "./path/life.xpm",
				info->data.resolution.x / 3, info->data.resolution.y / 15);
		ft_life_bar(info);
		info->count_patron += 5;
		info->img_patron = ft_create_img(info, "./path/patron.xpm",
				info->data.resolution.x / 15, info->data.resolution.y / 10);
		ft_patron_bar(info);
	}
}
