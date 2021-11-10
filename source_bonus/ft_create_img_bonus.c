/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 02:55:15 by ashea             #+#    #+#             */
/*   Updated: 2020/08/12 03:28:38 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img		ft_create_img_win(t_info *info)
{
	t_img	img;

	if (!(img.ptr = mlx_new_image(info->mlx.ptr,
					info->data.resolution.x, info->data.resolution.y)))
		ft_stop_all("image not create", info);
	if (!(img.addr = (unsigned int *)mlx_get_data_addr(img.ptr,
					&img.bits_per_pixel, &img.size_line, &img.endian)))
		ft_stop_all("image error", info);
	img.width = info->data.resolution.x;
	img.height = info->data.resolution.y;
	return (img);
}

t_img		ft_create_img(t_info *info, char *path, int size_x, int size_y)
{
	t_img	img;

	if (!(img.ptr = mlx_xpm_file_to_image(info->mlx.ptr, path,
					&img.width, &img.height)))
		ft_stop_all("image not found", info);
	if (!(img.addr = (unsigned int *)mlx_get_data_addr(img.ptr,
					&img.bits_per_pixel, &img.size_line, &img.endian)))
		ft_stop_all("image error", info);
	return (ft_create_img_scale(info, img, size_x, size_y));
}

t_img		ft_create_img_scale(t_info *info, t_img img, int size_x, int size_y)
{
	t_img	img2;
	int		i;
	int		j;

	if (!(img2.ptr = mlx_new_image(info->mlx.ptr, size_x, size_y)))
		ft_stop_all("image not create", info);
	img2.width = size_x;
	img2.height = size_y;
	if (!(img2.addr = (unsigned int *)mlx_get_data_addr(img2.ptr,
					&img2.bits_per_pixel, &img2.size_line, &img2.endian)))
		ft_stop_all("image error", info);
	i = 0;
	while (i < size_y)
	{
		j = 0;
		while (j < size_x)
		{
			img2.addr[(int)(i * img2.size_line / 4 + j)] =
				img.addr[(int)((i * img.height) / size_y * img.size_line / 4
						+ (j * img.width) / size_x)];
			j++;
		}
		i++;
	}
	return (img2);
}
