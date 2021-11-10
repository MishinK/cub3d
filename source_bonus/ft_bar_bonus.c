/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 22:04:55 by ashea             #+#    #+#             */
/*   Updated: 2020/08/13 23:24:41 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_life_bar(t_info *info)
{
	int		i;
	int		j;
	int		pos;

	if (info->count_life > 100)
		info->count_life = 100;
	info->life = ft_strjoin(ft_strjoin("LIFE: ",
				ft_itoa(info->count_life)), "%");
	i = info->img_life.width * info->count_life / 100;
	while (i < info->img_life.width)
	{
		j = 0;
		while (j < info->img_life.height)
		{
			pos = j * info->img_life.size_line / 4 + i;
			if (info->img_life.addr[pos] != 0x00000000)
				info->img_life.addr[pos] = info->img_life.addr[0];
			j++;
		}
		i++;
	}
}

void		ft_patron_bar(t_info *info)
{
	int		i;
	int		j;
	int		pos;

	if (info->count_patron > 15)
		info->count_patron = 15;
	info->patron = ft_strjoin("PATRON: ",
			ft_itoa(info->count_patron));
	i = info->img_patron.height * info->count_patron / 15;
	while (i < info->img_patron.height)
	{
		j = 0;
		while (j < info->img_patron.width)
		{
			pos = i * info->img_patron.size_line / 4 + j;
			if (info->img_patron.addr[pos] != 0x00000000)
				info->img_patron.addr[pos] = info->img_patron.addr[0];
			j++;
		}
		i++;
	}
}
