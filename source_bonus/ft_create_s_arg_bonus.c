/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_s_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 03:00:43 by ashea             #+#    #+#             */
/*   Updated: 2020/08/12 03:31:05 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_create_s_arg(t_info *info)
{
	int	i;
	int	j;

	if (!(info->s_arg = (t_sprite_arg **)malloc(sizeof(t_sprite_arg *)
					* info->data.map.y)))
		ft_stop_all("malloc", info);
	i = 0;
	while (i < info->data.map.y)
	{
		if (!(info->s_arg[i] = (t_sprite_arg *)malloc(sizeof(t_sprite_arg)
						* info->data.map.x)))
			ft_stop_all("malloc", info);
		j = 0;
		while (j < info->data.map.x)
		{
			if (info->data.map.content[i][j] == '2')
				info->s_arg[i][j] = (t_sprite_arg){1, 0, 2, 30, 0};
			else if (info->data.map.content[i][j] == '3')
				info->s_arg[i][j] = (t_sprite_arg){0, 0, 2, 30, 0};
			j++;
		}
		i++;
	}
}
