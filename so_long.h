/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:33:48 by temil-da          #+#    #+#             */
/*   Updated: 2024/06/07 14:53:47 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TSIZE 32

# include "utils/libft/libft.h"
# include "utils/minilibx/mlx.h"
# include <fcntl.h>

typedef struct s_map_layout
{
	int	walls;
	int	space;
	int	collectible;
	int	exit;
	int	player;
	int	error;
	int	rows;
	int	cols;
}			t_map_layout;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	char			**map_arr;
	void			*wall;
	void			*collectible;
	void			*player;
	void			*exit;
	void			*floor;
	int				width;
	int				height;
	int				px;
	int				py;
	t_map_layout	layout;
}			t_data;

char			**ft_process_map(char *name);
void			free_arr(char **map_arr);
int				ft_process_lines(char *path);
int				ft_check_map_valid(char **map_arr, t_data *data);
void			ft_count(int i, char *str, t_map_layout *layout, t_data *data);
void			ft_set_variables(t_map_layout *layout, char **map);
int				ft_check_components(t_map_layout layout);
int				ft_check_rectangular(char **map);
int				ft_strlen_so(const char *s);
int				ft_check_walls(char	**map);
int				ft_check_inner_walls(const char *str);
int				ft_check_upper_lower_walls(const char *str);
void			draw_tile(t_data *data, void *img, int x, int y);
void			load_images(t_data *data);
void			draw_map(t_data *data);
int				handle_keystroke(int keycode, t_data *data);
void			move_player(t_data *data, int x, int y);
void			exit_game(t_data *data);
int				ft_close(void *param);
int				ft_check_valid_path(char **map, t_data *data);
char			**ft_copy_map(char **map, t_data *data);
void			ft_flood_fill(t_data *data, int px, int py, t_map_layout *cpy);
void			ft_print_err_code(int err_code);

#endif