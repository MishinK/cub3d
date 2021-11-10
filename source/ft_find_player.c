/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:18:20 by ashea             #+#    #+#             */
/*   Updated: 2020/08/06 00:07:22 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_find_player(t_info *info)
{
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	while (i < info->data.map.y)
	{
		j = 0;
		while (j < info->data.map.x)
		{
			if (ft_strchr("NSWE", (info->data.map.content)[i][j]) != NULL)
				info->data.player = ft_return_player(j, i,
						(info->data.map.content)[i][j], &count);
			j++;
		}
		i++;
	}
	if (count == 0)
		ft_stop_all("player not found", info);
	if (count > 1)
		ft_stop_all("player duplicate", info);
}

t_player	ft_return_player(int x, int y, char content, int *count)
{
	(*count)++;
	if (content == 'N')
		return ((t_player){x * 64 + 64 / 2, y * 64 + 64 / 2, M_PI / 2});
	if (content == 'S')
		return ((t_player){x * 64 + 64 / 2, y * 64 + 64 / 2, 3 * M_PI / 2});
	if (content == 'E')
		return ((t_player){x * 64 + 64 / 2, y * 64 + 64 / 2, M_PI});
	return ((t_player){x * 64 + 64 / 2, y * 64 + 64 / 2, 0});
}
