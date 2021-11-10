/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_ceilling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:27:12 by ashea             #+#    #+#             */
/*   Updated: 2020/08/06 01:04:23 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_read_ceilling(t_info *info, char *line,
		char **information, int *valid)
{
	char	*trim;
	int		i;

	if (!(trim = ft_strtrim(line + 2, ",0123456789")))
		ft_stop_all("malloc", info);
	if (ft_strlen(trim) != 0)
		ft_stop_all("ceilling color 1", info);
	i = 0;
	while (information[i])
		i++;
	if (i != 2)
		ft_stop_all("ceilling color 2", info);
	ft_read_ceilling_dop(info, information);
	free(trim);
	(*valid)++;
}

void		ft_read_ceilling_dop(t_info *info, char **information)
{
	t_color	ceilling_color;
	char	**information_specific;
	int		i;

	if (!(information_specific = ft_split(information[1], ',')))
		ft_stop_all("malloc", info);
	i = 0;
	while (information_specific[i])
		i++;
	if (i != 3)
		ft_stop_all("ceilling color 3", info);
	ceilling_color.r = ft_atoi(information_specific[0]);
	ceilling_color.g = ft_atoi(information_specific[1]);
	ceilling_color.b = ft_atoi(information_specific[2]);
	if (ceilling_color.r < 0 || ceilling_color.g < 0 || ceilling_color.b < 0)
		ft_stop_all("ceilling color 4", info);
	info->data.ceilling_color = ft_create_color(ceilling_color);
	ft_printf("ceilling color %d, %d, %d\n", ceilling_color.r,
			ceilling_color.g, ceilling_color.b);
	i = 0;
	while (information_specific[i])
		free(information_specific[i++]);
	free(information_specific);
}
