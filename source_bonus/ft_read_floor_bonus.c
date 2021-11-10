/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:27:12 by ashea             #+#    #+#             */
/*   Updated: 2020/08/06 01:08:08 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	ft_create_color(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}

void			ft_read_floor(t_info *info, char *line,
		char **information, int *valid)
{
	char		*trim;
	int			i;

	if (!(trim = ft_strtrim(line + 2, ",0123456789")))
		ft_stop_all("malloc", info);
	if (ft_strlen(trim) != 0)
		ft_stop_all("floor color 1", info);
	i = 0;
	while (information[i])
		i++;
	if (i != 2)
		ft_stop_all("floor color 2", info);
	ft_read_floor_dop(info, information);
	free(trim);
	(*valid)++;
}

void			ft_read_floor_dop(t_info *info, char **information)
{
	t_color		floor_color;
	char		**information_specific;
	int			i;

	if (!(information_specific = ft_split(information[1], ',')))
		ft_stop_all("malloc", info);
	i = 0;
	while (information_specific[i])
		i++;
	if (i != 3)
		ft_stop_all("floor color 3", info);
	floor_color.r = ft_atoi(information_specific[0]);
	floor_color.g = ft_atoi(information_specific[1]);
	floor_color.b = ft_atoi(information_specific[2]);
	if (floor_color.r < 0 || floor_color.g < 0 || floor_color.b < 0)
		ft_stop_all("floor color 4", info);
	info->data.floor_color = ft_create_color(floor_color);
	ft_printf("floor color %d, %d, %d\n", floor_color.r,
			floor_color.g, floor_color.b);
	i = 0;
	while (information_specific[i])
		free(information_specific[i++]);
	free(information_specific);
}
