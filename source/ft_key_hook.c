/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:32:43 by ashea             #+#    #+#             */
/*   Updated: 2020/08/14 01:03:32 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_key(t_info *info, int keycode, int press)
{
	if (keycode == W_KEY)
		info->flag_w = press;
	if (keycode == S_KEY)
		info->flag_s = press;
	if (keycode == A_KEY)
		info->flag_a = press;
	if (keycode == D_KEY)
		info->flag_d = press;
	if (keycode == RIGHT_KEY)
		info->flag_right = press;
	if (keycode == LEFT_KEY)
		info->flag_left = press;
}

int		ft_key_hook_r(int keycode, t_info *info)
{
	ft_key(info, keycode, 0);
	return (1);
}

int		ft_key_hook(int keycode, t_info *info)
{
	ft_key(info, keycode, 1);
	if (keycode == ESC_KEY)
		ft_close(info);
	return (1);
}
