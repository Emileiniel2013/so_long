/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:54:33 by temil-da          #+#    #+#             */
/*   Updated: 2024/06/05 19:53:07 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_upper_lower_walls(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1' || str[i] == '\n')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_check_inner_walls(const char *str)
{
	int	i;

	i = 0;
	if (str[i] != '1')
		return (1);
	i = ft_strlen_so(str);
	if (str[i - 1] == '1')
		return (0);
	else
		return (1);
}

int	ft_check_walls(char	**map)
{
	int	rows;
	int	i;

	i = 1;
	rows = 0;
	while (map[rows] != NULL)
		rows++;
	if (ft_check_upper_lower_walls(map[0]) == 1)
		return (1);
	if (ft_check_upper_lower_walls(map[rows - 1]) == 1)
		return (1);
	while (i < (rows - 1))
	{
		if (ft_check_inner_walls(map[i]) == 1)
			return (1);
		else
			i++;
	}
	return (0);
}

void	draw_tile(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, img, x * TSIZE, y * TSIZE);
}

int	ft_close(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	exit_game(data);
	return (0);
}
