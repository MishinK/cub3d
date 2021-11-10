/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:15:35 by ashea             #+#    #+#             */
/*   Updated: 2020/08/13 02:20:37 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_create_map_pixel_mini(t_info *info)
{
	int		i[8];
	float	f[4];

	ft_create_map_pixel_mini_dop(info, i);
	while (i[5] < i[4])
	{
		i[6] = 0;
		while (i[6] < i[3])
		{
			i[7] = i[5] * info->img_win.size_line / 4 + i[6];
			if (info->data.map.content[(int)(i[5]
						/ i[2])][(int)(i[6] / i[1])] == '1')
				info->img_win.addr[i[7]] = 0x00800000;
			else if (info->data.map.content[(int)(i[5] /
						i[2])][(int)(i[6] / i[1])] == '2')
				info->img_win.addr[i[7]] = 0x00D2691E;
			else
				info->img_win.addr[i[7]] = 0x00808080;
			(i[6])++;
		}
		(i[5])++;
	}
	ft_map_pixel_mini_dist(info, i[1], i[2], f);
}

void		ft_create_map_pixel_mini_dop(t_info *info, int *i)
{
	i[0] = (info->data.resolution.x < info->data.resolution.y)
		? info->data.resolution.x : info->data.resolution.y;
	i[1] = i[0] / info->data.map.x / 4;
	i[2] = i[0] / info->data.map.y / 4;
	i[3] = info->data.map.x * i[1];
	i[4] = info->data.map.y * i[2];
	i[5] = 0;
}

void		ft_map_pixel_mini_dist(t_info *info, int k_x, int k_y, float *f)
{
	int		i[2];

	f[0] = 0;
	i[0] = 0;
	i[1] = info->data.map.x * k_x;
	while (i[0] < i[1])
	{
		f[1] = 0;
		while (f[1] < 20)
		{
			f[2] = k_x * info->data.player.x / 64
				+ f[1] * cos(info->data.player.look + f[0]);
			f[3] = k_y * info->data.player.y / 64
				+ f[1] * sin(info->data.player.look + f[0]);
			if (ft_if_end_of_map(info, k_x, k_y, f))
				break ;
			if (ft_if_walls(info, k_x, k_y, f))
				break ;
			info->img_win.addr[(int)f[3] * info->img_win.size_line / 4
				+ (int)f[2]] = 0x000000FF;
			(f[1])++;
		}
		f[0] = (i[0] - i[1] / 2) * M_PI / 3 / i[1];
		(i[0])++;
	}
}

int			ft_if_end_of_map(t_info *info, int k_x, int k_y, float *f)
{
	return ((int)(f[3] / k_y) >= info->data.map.y || (int)(f[3] < 0 ||
				(int)(f[2] / k_x) >= info->data.map.x || (int)(f[2]) < 0));
}

int			ft_if_walls(t_info *info, int k_x, int k_y, float *f)
{
	return (info->data.map.content[(int)(f[3] /
				k_y)][(int)(f[2] / k_x)] == '1' ||
			info->data.map.content[(int)(f[3] /
				k_y)][(int)(f[2] / k_x)] == '4');
}
