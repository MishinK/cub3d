/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:38:44 by ashea             #+#    #+#             */
/*   Updated: 2020/08/12 04:59:51 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_color_walls(t_info *info, int y, t_distance *distance)
{
	int	i;
	int	j;
	int	pos;

	i = distance->hit * 64;
	j = ((float)y / (float)distance->h) * 64;
	pos = j * info->img_we.size_line / 4 + i;
	if (distance->vertical == 1 && ft_look_right(distance->angle) == 1)
		return (ft_color_walls_we(info, pos, distance));
	if (distance->vertical == 1 && ft_look_right(distance->angle) == -1)
		return (ft_color_walls_ea(info, pos, distance));
	if (distance->vertical == 0 && ft_look_up(distance->angle) == 1)
		return (ft_color_walls_no(info, pos, distance));
	if (distance->vertical == 0 && ft_look_up(distance->angle) == -1)
		return (ft_color_walls_so(info, pos, distance));
	return (0);
}

int		ft_color_walls_we(t_info *info, int pos, t_distance *distance)
{
	if (distance->flag_door == 1)
		return (info->img_we_d.addr[pos]);
	if (distance->y % 6 == 0)
		return (info->img_we2.addr[pos]);
	if (distance->y % 3 == 0)
		return (info->img_we3.addr[pos]);
	return (info->img_we.addr[pos]);
}

int		ft_color_walls_ea(t_info *info, int pos, t_distance *distance)
{
	if (distance->flag_door == 1)
		return (info->img_ea_d.addr[pos]);
	if (distance->y % 6 == 0)
		return (info->img_ea2.addr[pos]);
	if (distance->y % 3 == 0)
		return (info->img_ea3.addr[pos]);
	return (info->img_ea.addr[pos]);
}

int		ft_color_walls_no(t_info *info, int pos, t_distance *distance)
{
	if (distance->flag_door == 1)
		return (info->img_no_d.addr[pos]);
	if (distance->x % 6 == 0)
		return (info->img_no2.addr[pos]);
	if (distance->x % 3 == 0)
		return (info->img_no3.addr[pos]);
	return (info->img_no.addr[pos]);
}

int		ft_color_walls_so(t_info *info, int pos, t_distance *distance)
{
	if (distance->flag_door == 1)
		return (info->img_so_d.addr[pos]);
	if (distance->x % 6 == 0)
		return (info->img_so2.addr[pos]);
	if (distance->x % 3 == 0)
		return (info->img_so3.addr[pos]);
	return (info->img_so.addr[pos]);
}
