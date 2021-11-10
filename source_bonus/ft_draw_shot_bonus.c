/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_shot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 19:00:11 by ashea             #+#    #+#             */
/*   Updated: 2020/08/12 02:50:29 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_draw_shot(int button, int x, int y, t_info *info)
{
	info->time_gun = 1;
	info->flag_button = 1;
	return (1);
}

int			ft_draw_shot_hit(int button, int x, int y, t_info *info)
{
	int		pid;

	if (info->count_patron > 0)
	{
		pid = fork();
		if (pid == 0)
		{
			system("afplay ./sound/gun.wav");
			exit(0);
		}
		info->count_patron--;
		ft_patron_bar(info);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			system("afplay ./sound/knife.wav");
			exit(0);
		}
	}
	info->flag_button = 0;
	return (1);
}
