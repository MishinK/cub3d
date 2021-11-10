/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_death_sprite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 22:16:17 by ashea             #+#    #+#             */
/*   Updated: 2020/08/13 22:34:49 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_death_sprite(t_info *info, int flag_head_shot, int x, int y)
{
	int		pid;

	info->flag_button = 0;
	(info->data.map.content)[y][x] = 0;
	pid = fork();
	if (pid == 0)
	{
		if (flag_head_shot)
			system("afplay ./sound/head_shot.wav");
		else
			system("afplay ./sound/death.wav");
		exit(0);
	}
	ft_find_sprite(info);
	info->count_sprites--;
	return (1);
}

void		ft_hit_sprite(t_info *info, int x, int y)
{
	int		pid;

	info->flag_button = 0;
	(info->s_arg[y][x]).life--;
	pid = fork();
	if (pid == 0)
	{
		system("afplay ./sound/hit.wav");
		exit(0);
	}
}
