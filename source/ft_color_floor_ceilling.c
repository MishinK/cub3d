/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_floor_ceilling.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 03:10:54 by ashea             #+#    #+#             */
/*   Updated: 2020/08/13 15:33:11 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_color_floor(t_info *info, t_distance *distance, int y)
{
	return (info->data.floor_color);
}

int			ft_color_ceilling(t_info *info, t_distance *distance, int i, int j)
{
	return (info->data.ceilling_color);
}
