/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 20:49:23 by ashea             #+#    #+#             */
/*   Updated: 2020/08/12 01:32:44 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_valid_line(t_info *info, char *line, int len)
{
	int		i;

	if (line[0] == ' ')
		if (line[1] != ' ' && line[1] != '1')
			return (0);
	if (len > 1 && line[len - 1] == ' ')
		if (line[len - 2] != ' ' && line[len - 2] != '1')
			return (0);
	i = 1;
	while (i < len - 1)
	{
		if (line[i] == ' ' && ((line[i - 1] != ' ' && line[i - 1] != '1')
					|| (line[i + 1] != ' ' && line[i + 1] != '1')))
			return (0);
		i++;
	}
	return (ft_valid_line_dop(info, line));
}

int			ft_valid_line_dop(t_info *info, char *line)
{
	char	*trim;
	char	*mega_trim;

	trim = ft_strtrim(line, " ");
	if (!(trim = ft_strtrim(line, "  ")))
		ft_stop_all("malloc", info);
	if (trim[0] != '1' || trim[ft_strlen(trim) - 1] != '1')
	{
		free(trim);
		return (0);
	}
	if (!(mega_trim = ft_strtrim(trim, "012NSWE ")))
		ft_stop_all("malloc", info);
	if (ft_strlen(mega_trim) != 0)
	{
		free(trim);
		free(mega_trim);
		return (0);
	}
	free(trim);
	free(mega_trim);
	return (1);
}

int			ft_valid_column(t_info *info)
{
	int		i;
	int		j;
	char	*column;

	j = 0;
	while (j < info->data.map.x)
	{
		if (!(column = (char *)malloc(sizeof(char) * (info->data.map.y + 1))))
			ft_stop_all("malloc", info);
		i = 0;
		while (i < info->data.map.y)
		{
			column[i] = (info->data.map.content)[i][j];
			i++;
		}
		column[i] = '\0';
		if (!ft_valid_line(info, column, info->data.map.y))
			return (0);
		free(column);
		j++;
	}
	return (1);
}

int			ft_valid_map(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->data.map.y)
		if (!ft_valid_line(info,
					(info->data.map.content)[i++], info->data.map.x))
			return (0);
	if (!ft_valid_column(info))
		return (0);
	return (1);
}
