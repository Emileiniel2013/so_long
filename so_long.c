/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:48:25 by temil-da          #+#    #+#             */
/*   Updated: 2024/06/06 16:07:30 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data			data;
	char			**map_arr;
	int				err_code;

	map_arr = NULL;
	if (argc != 2)
		return (ft_printf("Error!\nUsage: %s <map_name.ber>\n", argv[0]), 1);
	map_arr = ft_process_map(argv[1]);
	if (map_arr == NULL)
		return (ft_printf("Error!\nInvalid map!!!\n"), 1);
	err_code = ft_check_map_valid(map_arr, &data);
	if (err_code != 0)
		return (ft_print_err_code(err_code), free_arr(map_arr), 1);
	data.map_arr = map_arr;
	load_images(&data);
	draw_map(&data);
	mlx_key_hook(data.win, handle_keystroke, &data);
	mlx_hook(data.win, 17, 0, ft_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
