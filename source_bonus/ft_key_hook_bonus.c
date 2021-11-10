/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:32:43 by ashea             #+#    #+#             */
/*   Updated: 2020/08/13 22:23:15 by ashea            ###   ########.fr       */
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
	if (keycode == UP_KEY)
		info->flag_up = press;
	if (keycode == DOWN_KEY)
		info->flag_down = press;
	if (keycode == Q_KEY)
		info->flag_mini = press;
	if (keycode == SPACE_KEY)
		ft_press_space(info, press);
}

int		ft_key_hook_r(int keycode, t_info *info)
{
	if (info->count_life > 0)
		ft_key(info, keycode, 0);
	return (1);
}

int		ft_key_hook(int keycode, t_info *info)
{
	if (info->count_life > 0 && info->count_sprites > 0)
		ft_key(info, keycode, 1);
	if (keycode == ESC_KEY)
		ft_close(info);
	if (keycode == TAB_KEY)
		ft_press_tab(info);
	if (keycode == SHIFT_KEY && info->count_sprites == 0 && info->flag_lvl < 3)
		ft_press_shift(info);
	info->flag_instruction = 0;
	return (1);
}
