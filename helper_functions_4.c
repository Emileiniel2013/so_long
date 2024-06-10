/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:21:32 by temil-da          #+#    #+#             */
/*   Updated: 2024/06/06 18:02:31 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_copy_map(char **map, t_data *data)
{
	int		i;
	char	**map_copy;

	i = 0;
	map_copy = malloc(sizeof(char *) * (data->layout.rows + 1));
	if (!map_copy)
		return (NULL);
	while (i < data->layout.rows)
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	map_copy[data->layout.rows] = NULL;
	return (map_copy);
}

void	ft_flood_fill(t_data *data, int px, int py, t_map_layout *layout)
{
	if (data->map_arr[py][px] == '1' || data->map_arr[py][px] == 'V')
		return ;
	if (data->map_arr[py][px] == 'E')
		layout->exit--;
	if (data->map_arr[py][px] == 'C')
		layout->collectible--;
	data->map_arr[py][px] = 'V';
	ft_flood_fill(data, px - 1, py, layout);
	ft_flood_fill(data, px + 1, py, layout);
	ft_flood_fill(data, px, py - 1, layout);
	ft_flood_fill(data, px, py + 1, layout);
}

void	ft_print_err_code(int err_code)
{
	if (err_code == 1)
	{
		ft_printf("\x1b[31mERROR: UNKNOWN SYMBOL!");
		ft_printf("\x1b[0m\nMake sure you only une 1, 0, P, E, and C\n");
	}
	if (err_code == 2)
	{
		ft_printf("\x1b[31mERROR: INCORECT NUMBER OF COMPONENTS!\x1b[0m\nMake");
		ft_printf(" sure you have 1 exit, at least 1 collectible and 1 star");
		ft_printf("ting position!\n");
	}
	if (err_code == 3)
	{
		ft_printf("\x1b[31mERROR: INCORECT MAP SHAPE!\x1b[0m\nMake sure your");
		ft_printf(" map is an equal rectangle!\n");
	}
	if (err_code == 4)
		ft_printf("\x1b[31mERROR!\x1b[0m\nMap is not surounded by walls!\n");
	if (err_code == 5)
	{
		ft_printf("\x1b[31mERROR:COMPONENTS INACCESSIBLE\x1b[0m\nMake sure al");
		ft_printf("l collectibles and exit are accessible by the player!\n");
	}
}
