/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:08:57 by temil-da          #+#    #+#             */
/*   Updated: 2024/06/06 17:35:12 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_count(int i, char *str, t_map_layout *layout, t_data *data)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] == '0')
			layout->space++;
		else if (str[j] == '1')
			layout->walls++;
		else if (str[j] == 'C')
			layout->collectible++;
		else if (str[j] == 'E')
			layout->exit++;
		else if (str[j] == 'P')
		{
			layout->player++;
			data->px = j;
			data->py = i;
		}
		else if (str[j] == '\n' && str[j + 1] == '\0')
			break ;
		else
			layout->error++;
		j++;
	}
}

int	ft_check_components(t_map_layout layout)
{
	if (layout.player != 1)
		return (1);
	if (layout.exit != 1)
		return (1);
	if (layout.collectible < 1)
		return (1);
	return (0);
}

void	ft_set_variables(t_map_layout *layout, char **map)
{
	int	i;

	i = 0;
	layout->collectible = 0;
	layout->error = 0;
	layout->exit = 0;
	layout->player = 0;
	layout->space = 0;
	layout->walls = 0;
	layout->cols = ft_strlen_so(map[0]);
	while (map[i] != NULL)
		i++;
	layout->rows = i;
}

int	ft_check_rectangular(char **map)
{
	int	rows;
	int	cols;
	int	i;

	i = 1;
	rows = 0;
	cols = 0;
	while (map[rows] != NULL)
		rows++;
	if (rows == 0)
		return (1);
	cols = (ft_strlen_so(map[0]));
	if (cols < rows)
		return (1);
	while (i < rows)
	{
		if (ft_strlen_so(map[i]) != cols)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen_so(const char *s)
{
	int	a;

	a = 0;
	while (*s && *s != '\n')
	{
		s++;
		a++;
	}
	return (a);
}
