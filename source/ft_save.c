/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:15:12 by ashea             #+#    #+#             */
/*   Updated: 2020/08/12 00:47:23 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				ft_create_bm_file(int size, int size_x, int size_y, int fd)
{
	unsigned char	title[54];
	int				i;

	i = 0;
	while (i < 54)
		title[i++] = 0;
	title[0] = 'B';
	title[1] = 'M';
	title[2] = size % 256;
	title[3] = size / 256 % 256;
	title[4] = size / 256 / 256 % 256;
	title[5] = size / 256 / 256 / 256 % 256;
	title[10] = '6';
	title[14] = '(';
	title[18] = size_x % 256;
	title[22] = size_y % 256;
	title[19] = size_x / 256 % 256;
	title[23] = size_y / 256 % 256;
	title[20] = size_x / 256 / 256 % 256;
	title[24] = size_y / 256 / 256 % 256;
	title[26] = 1;
	title[28] = ' ';
	write(fd, title, 54);
}

void				ft_save_screen(t_info *info)
{
	int				fd;
	int				i;
	int				j;
	int				pos;

	ft_paint_map(info);
	fd = open("screen.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
		ft_stop_all("screen not created", info);
	ft_create_bm_file(info->data.resolution.x * info->data.resolution.y * 4
			+ 54, info->data.resolution.x, info->data.resolution.y, fd);
	i = info->data.resolution.y - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < info->data.resolution.x)
		{
			pos = i * info->img_win.size_line / 4 + j;
			write(fd, &(info->img_win.addr[pos]), 4);
			j++;
		}
		i--;
	}
	close(fd);
	ft_close(info);
}
