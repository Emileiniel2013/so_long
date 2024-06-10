/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:45:13 by temil-da          #+#    #+#             */
/*   Updated: 2024/06/07 14:55:42 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->layout.cols * TSIZE, \
	data->layout.rows * TSIZE, "so_long");
	data->wall = mlx_xpm_file_to_image(data->mlx, \
	"textures/wall.xpm", &data->width, &data->height);
	data->exit = mlx_xpm_file_to_image(data->mlx, \
	"textures/exit.xpm", &data->width, &data->height);
	data->floor = mlx_xpm_file_to_image(data->mlx, \
	"textures/floor.xpm", &data->width, &data->height);
	data->collectible = mlx_xpm_file_to_image(data->mlx, \
	"textures/colectible.xpm", &data->width, &data->height);
	data->player = mlx_xpm_file_to_image(data->mlx, \
	"textures/player.xpm", &data->width, &data->height);
}

void	free_arr(char **map_arr)
{
	char	**temp;

	temp = map_arr;
	if (map_arr == NULL)
		return ;
	while (*map_arr != NULL)
	{
		free(*map_arr);
		map_arr++;
	}
	free(temp);
}

int	ft_process_lines(char *path)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		free(str);
		i++;
	}
	if (str)
		free(str);
	close(fd);
	return (i);
}

void	draw_map(t_data *data)
{
	int		x;
	int		y;
	char	tile;

	x = 0;
	while (x < data->layout.rows)
	{
		y = 0;
		while (y < data->layout.cols)
		{
			tile = data->map_arr[x][y];
			draw_tile(data, data->floor, y, x);
			if (tile == '1')
				draw_tile(data, data->wall, y, x);
			else if (tile == 'P')
				draw_tile(data, data->player, y, x);
			else if (tile == 'E')
				draw_tile(data, data->exit, y, x);
			else if (tile == 'C')
				draw_tile(data, data->collectible, y, x);
			y++;
		}
		x++;
	}
}

int	ft_check_valid_path(char **map, t_data *data)
{
	char			**map_copy;
	t_map_layout	layout;
	int				i;

	i = 0;
	layout.collectible = data->layout.collectible;
	layout.exit = 1;
	map_copy = ft_copy_map(map, data);
	data->map_arr = map_copy;
	if (map_copy == NULL)
		return (1);
	ft_flood_fill(data, data->px, data->py, &layout);
	free_arr(data->map_arr);
	data->map_arr = NULL;
	if (layout.collectible == 0 && layout.exit == 0)
		return (0);
	else
		return (1);
}
