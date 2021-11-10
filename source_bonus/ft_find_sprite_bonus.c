/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:19:13 by ashea             #+#    #+#             */
/*   Updated: 2020/08/12 04:41:08 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_find_sprite(t_info *info)
{
	int			i;
	int			j;

	info->data.s.count = 0;
	i = 0;
	while (i < info->data.map.y)
	{
		j = 0;
		while (j < info->data.map.x)
		{
			if ((info->data.map.content)[i][j] == '2')
				info->data.s.count++;
			else if ((info->data.map.content)[i][j] == '3')
				info->data.s.count++;
			j++;
		}
		i++;
	}
	if (!(info->data.s.sprites =
				(t_sprite *)malloc(sizeof(t_sprite) * info->data.s.count)))
		ft_stop_all("malloc", info);
	ft_return_sprite(info);
	ft_sort_sprite(info);
}

void			ft_return_sprite(t_info *info)
{
	int			i;
	int			j;
	int			count;

	i = 0;
	count = info->data.s.count;
	while (i < info->data.map.y)
	{
		j = 0;
		while (j < info->data.map.x)
		{
			if ((info->data.map.content)[i][j] == '2'
					|| (info->data.map.content)[i][j] == '3')
				info->data.s.sprites[--count] =
					(t_sprite){j * 64 + 64 / 2, i * 64 + 64 / 2,
						sqrt(pow(info->data.player.x -
									(j * 64 + 64 / 2), 2)
								+ pow(info->data.player.y -
									(i * 64 + 64 / 2), 2)) / 64};
			j++;
		}
		i++;
	}
}

void			ft_sort_sprite(t_info *info)
{
	int			i;
	int			j;
	t_sprite	sprite;

	i = 1;
	while (i < info->data.s.count)
	{
		j = 0;
		while (j < info->data.s.count - i)
		{
			if ((info->data.s.sprites[j]).dist >
					(info->data.s.sprites[j + 1]).dist)
			{
				sprite = info->data.s.sprites[j];
				info->data.s.sprites[j] = info->data.s.sprites[j + 1];
				info->data.s.sprites[j + 1] = sprite;
			}
			j++;
		}
		i++;
	}
}
