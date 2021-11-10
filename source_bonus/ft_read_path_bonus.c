/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:29:05 by ashea             #+#    #+#             */
/*   Updated: 2020/08/06 01:28:06 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_read_path_no(t_info *info, char **information, int *valid)
{
	int		i;

	i = 0;
	while (information[i])
		i++;
	if (i != 2)
		ft_stop_all("NO path 1", info);
	info->data.path.no = ft_strdup(information[1]);
	ft_printf("NO path: %s\n", info->data.path.no);
	(*valid)++;
}

void		ft_read_path_so(t_info *info, char **information, int *valid)
{
	int		i;

	i = 0;
	while (information[i])
		i++;
	if (i != 2)
		ft_stop_all("SO path 1", info);
	info->data.path.so = ft_strdup(information[1]);
	ft_printf("SO path: %s\n", info->data.path.so);
	(*valid)++;
}

void		ft_read_path_we(t_info *info, char **information, int *valid)
{
	int		i;

	i = 0;
	while (information[i])
		i++;
	if (i != 2)
		ft_stop_all("WE path 1", info);
	info->data.path.we = ft_strdup(information[1]);
	ft_printf("WE path: %s\n", info->data.path.we);
	(*valid)++;
}

void		ft_read_path_ea(t_info *info, char **information, int *valid)
{
	int		i;

	i = 0;
	while (information[i])
		i++;
	if (i != 2)
		ft_stop_all("EA path 1", info);
	info->data.path.ea = ft_strdup(information[1]);
	ft_printf("EA path: %s\n", info->data.path.ea);
	(*valid)++;
}

void		ft_read_path_s(t_info *info, char **information, int *valid)
{
	int i;

	i = 0;
	while (information[i])
		i++;
	if (i != 2)
		ft_stop_all("S path 1", info);
	info->data.path.s = ft_strdup(information[1]);
	ft_printf("S path: %s\n", info->data.path.s);
	(*valid)++;
}
