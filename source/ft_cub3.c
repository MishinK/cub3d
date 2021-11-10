/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:14:22 by ashea             #+#    #+#             */
/*   Updated: 2020/08/12 00:37:05 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_draw(t_info *info)
{
	mlx_hook(info->mlx.win, 2, 0, ft_key_hook, info);
	mlx_hook(info->mlx.win, 3, 0, ft_key_hook_r, info);
	mlx_hook(info->mlx.win, 17, 0, ft_close_x, info);
	mlx_loop_hook(info->mlx.ptr, ft_paint_map, info);
	mlx_loop(info->mlx.ptr);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_info	info;

	if (argc == 2 || argc == 3)
	{
		if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) == NULL)
			ft_stop_all("expect:\"*.cub\"", &info);
		fd = open(argv[1], O_RDONLY);
		if (fd <= 0)
			ft_stop_all("open(), try to enter \"make run\"", &info);
		ft_read_file(&info, fd);
		close(fd);
		if (argc == 3 && ft_strcmp(argv[2], "--save"))
			ft_stop_all("wrong flag, expected: \"--save\"", &info);
		else if (argc == 3)
			ft_save_screen(&info);
		ft_draw(&info);
	}
	else
		ft_stop_all("wrong arguments", &info);
	return (0);
}
