/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 01:59:09 by ashea             #+#    #+#             */
/*   Updated: 2020/08/13 22:31:43 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_press_space(t_info *info, int press)
{
	if (press == 1 && info->flag_squat == 0)
	{
		info->look_up -= info->data.resolution.y / 10;
		info->flag_squat = 1;
	}
	if (press == 0)
	{
		info->look_up += info->data.resolution.y / 10;
		info->flag_squat = 0;
	}
}

void		ft_press_tab(t_info *info)
{
	int		y;
	int		x;

	y = info->data.player.y / 64;
	x = info->data.player.x / 64;
	if (info->data.map.content[y + 1][x] == '4')
		ft_open_door(info, y + 1, x);
	else if (info->data.map.content[y + 1][x] == '5')
		ft_close_door(info, y + 1, x);
	if (info->data.map.content[y - 1][x] == '4')
		ft_open_door(info, y - 1, x);
	else if (info->data.map.content[y - 1][x] == '5')
		ft_close_door(info, y - 1, x);
	if (info->data.map.content[y][x + 1] == '4')
		ft_open_door(info, y, x + 1);
	else if (info->data.map.content[y][x + 1] == '5')
		ft_close_door(info, y, x + 1);
	if (info->data.map.content[y][x - 1] == '4')
		ft_open_door(info, y, x - 1);
	else if (info->data.map.content[y][x - 1] == '5')
		ft_close_door(info, y, x - 1);
}

void		ft_press_shift(t_info *info)
{
	int		fd;
	char	*lvl;

	info->flag_lvl++;
	lvl = ft_strjoin("./map/map", ft_itoa(info->flag_lvl));
	lvl = ft_strjoin(lvl, ".cub");
	if (ft_strnstr(lvl, ".cub", ft_strlen(lvl)) == NULL)
		ft_stop_all("expect:\"*.cub\"", info);
	fd = open(lvl, O_RDONLY);
	if (fd <= 0)
		ft_stop_all("open(), try to enter \"make run\"", info);
	ft_read_file(info, fd);
	close(fd);
	free(lvl);
}
