/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 01:38:02 by ashea             #+#    #+#             */
/*   Updated: 2020/08/12 02:09:44 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_stop_all(const char *error_str, t_info *info)
{
	perror(error_str);
	ft_memset(info, 0, sizeof(t_info));
	system("killall afplay");
	exit(-1);
}

int		ft_close(t_info *info)
{
	mlx_destroy_window(info->mlx.ptr, info->mlx.win);
	system("killall afplay");
	exit(0);
}

int		ft_close_x(t_info *info)
{
	system("killall afplay");
	exit(1);
}
