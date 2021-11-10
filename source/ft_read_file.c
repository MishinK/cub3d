/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:30:24 by ashea             #+#    #+#             */
/*   Updated: 2020/08/06 01:46:06 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_read_file(t_info *info, int ft)
{
	char	*line;
	char	*trim;
	int		valid;

	valid = 0;
	while (ft_get_next_line(ft, &line))
	{
		trim = ft_strtrim(line, "012NSEW ");
		if (ft_strlen(line) != 0 && ft_strlen(trim) == 0)
			ft_read_map(info, line, &valid, ft);
		else
			ft_read_file_arguments(info, line, &valid);
		free(trim);
		free(line);
	}
	if (ft_strcmp(line, "") != 0)
		ft_stop_all("extra line", info);
	free(line);
	if (valid != 9)
		ft_stop_all("few arguments", info);
	ft_find_player(info);
	ft_find_sprite(info);
	ft_create_info(info);
}

void		ft_read_file_arguments(t_info *info, char *line, int *valid)
{
	char	**information;

	information = ft_split(line, ' ');
	if (!ft_strcmp(information[0], "R"))
		ft_read_resolution(info, line, information, valid);
	else if (!ft_strcmp(information[0], "F"))
		ft_read_floor(info, line, information, valid);
	else if (!ft_strcmp(information[0], "C"))
		ft_read_ceilling(info, line, information, valid);
	else if (!ft_strcmp(information[0], "NO"))
		ft_read_path_no(info, information, valid);
	else if (!ft_strcmp(information[0], "SO"))
		ft_read_path_so(info, information, valid);
	else if (!ft_strcmp(information[0], "WE"))
		ft_read_path_we(info, information, valid);
	else if (!ft_strcmp(information[0], "EA"))
		ft_read_path_ea(info, information, valid);
	else if (!ft_strcmp(information[0], "S"))
		ft_read_path_s(info, information, valid);
	else if (ft_strcmp(information[0], ""))
		ft_stop_all("extra line", info);
}

void		ft_read_resolution(t_info *info, char *line,
		char **information, int *valid)
{
	char	*trim;
	int		i;

	if (!(trim = ft_strtrim(line + 1, " 0123456789")))
		ft_stop_all("malloc", info);
	if (ft_strlen(trim) != 0)
		ft_stop_all("resolution 1", info);
	i = 0;
	while (information[i])
		i++;
	if (i != 3)
		ft_stop_all("resolution 2", info);
	info->data.resolution.x = ft_atoi(information[1]);
	info->data.resolution.y = ft_atoi(information[2]);
	if (info->data.resolution.x <= 0 || info->data.resolution.y <= 0)
		ft_stop_all("resolution 3", info);
	free(trim);
	(*valid)++;
}
