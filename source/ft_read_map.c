/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:23:20 by ashea             #+#    #+#             */
/*   Updated: 2020/08/12 00:46:16 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_read_map(t_info *info, char *line, int *valid, int ft)
{
	char		*world_map;
	int			x;
	int			y;

	world_map = ft_strdup("");
	y = 0;
	x = ft_strlen(line);
	while (ft_strlen(line) != 0 &&
			ft_strlen(ft_strtrim(line, "012NSEW ")) == 0)
	{
		if (ft_strlen(line) > x)
			x = ft_strlen(line);
		world_map = ft_strjoin(world_map, line);
		world_map = ft_strjoin(world_map, "\n");
		y++;
		ft_get_next_line(ft, &line);
	}
	if (ft_strlen(world_map) == 0)
		ft_stop_all("world_map empty", info);
	ft_printf("world_map:\n%s", world_map);
	info->data.map = ft_create_map(info, x, y, world_map);
	if (ft_valid_map(info) == 0)
		ft_stop_all("fail valid map\n", info);
	free(world_map);
	(*valid)++;
}

t_map			ft_create_map(t_info *info, int x, int y, char *world_map)
{
	int			size[3];
	char		**content;
	char		*temp;

	size[0] = 0;
	if (!(content = ft_split(world_map, '\n')))
		ft_stop_all("malloc", info);
	while (size[0] < y)
	{
		size[1] = 0;
		size[2] = ft_strlen(content[size[0]]);
		if (!(temp = (char *)malloc(sizeof(char) * (x + 1))))
			ft_stop_all("malloc", info);
		while (size[1] < x)
			if (size[1] >= size[2] || content[size[0]][size[1]] == ' ')
				temp[size[1]++] = ' ';
			else
				temp[size[1]++] = content[size[0]][size[1]];
		temp[size[1]] = '\0';
		free(content[size[0]]);
		content[size[0]++] = temp;
	}
	content[size[0]] = NULL;
	return ((t_map){x, y, content});
}
