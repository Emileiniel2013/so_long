/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   important_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:30:47 by temil-da          #+#    #+#             */
/*   Updated: 2024/06/07 14:58:01 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_process_map(char *name)
{
	char	**map_arr;
	char	*path;
	int		i;
	int		fd;

	path = ft_strjoin("maps/", name);
	i = ft_process_lines(path);
	if (i == -1)
		return (free(path), NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (free(path), NULL);
	map_arr = malloc(sizeof(char *) * (i + 1));
	if (!map_arr)
		return (free(path), close(fd), NULL);
	i = 0;
	while (1)
	{
		map_arr[i] = get_next_line(fd);
		if (map_arr[i] == NULL)
			break ;
		i++;
	}
	return (free(path), close(fd), map_arr);
}

int	ft_check_map_valid(char **map_arr, t_data *data)
{
	t_map_layout	layout;
	int				i;

	i = 0;
	ft_set_variables(&layout, map_arr);
	while (map_arr[i] != NULL)
	{
		ft_count(i, map_arr[i], &layout, data);
		if (layout.error == 1)
			return (1);
		i++;
	}
	data->layout = layout;
	if (ft_check_components(layout) == 1)
		return (2);
	if (ft_check_rectangular(map_arr) == 1)
		return (3);
	if (ft_check_walls(map_arr) == 1)
		return (4);
	if (ft_check_valid_path(map_arr, data) == 1)
		return (5);
	return (0);
}

int	handle_keystroke(int keycode, t_data *data)
{
	if (keycode == 13)
		move_player(data, 0, -1);
	if (keycode == 0)
		move_player(data, -1, 0);
	if (keycode == 1)
		move_player(data, 0, 1);
	if (keycode == 2)
		move_player(data, 1, 0);
	if (keycode == 53)
		exit_game(data);
	return (0);
}

void	move_player(t_data *data, int x, int y)
{
	static int	i = 0;

	if (data->map_arr[data->py + y][data->px + x] == '1')
		return ;
	if (data->map_arr[data->py + y][data->px + x] == 'C')
	{
		data->layout.collectible--;
		data->map_arr[data->py + y][data->px + x] = '0';
	}
	if (data->map_arr[data->py + y][data->px + x] == 'E' && \
	data->layout.collectible == 0)
	{
		ft_printf("Number of moves: %d\nCongratulations! You won!\n", ++i);
		exit_game(data);
	}
	else if (data->map_arr[data->py + y][data->px + x] == 'E' \
	&& data->layout.collectible != 0)
		return ;
	data->map_arr[data->py][data->px] = '0';
	data->px += x;
	data->py += y;
	data->map_arr[data->py][data->px] = 'P';
	draw_map(data);
	ft_printf("Number of moves: %d\n", ++i);
}

void	exit_game(t_data *data)
{
	free_arr(data->map_arr);
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
}
