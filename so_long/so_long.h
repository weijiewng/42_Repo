/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:06:21 by wewang            #+#    #+#             */
/*   Updated: 2022/11/24 11:41:12 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"

# define EMPTY '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define MAP_EXIT 'E'
# define STARTING_POSITION 'P'
# define BUFF_SIZE 1

# define X_SIZE 51
# define Y_SIZE 51

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define MALLOC_ERROR "Error\nError while trying to malloc file space!\n"

// Map errors
# define NO_FILE "Error\nThere is no .ber file available!\n"
# define NOT_BIG_MAP "Error\nMap is not big enough\n"
# define NOT_RECTANGULAR "Error\nMap is not rectengular!\n"

// Character errors
# define NOT_SURROUNDED_WALL "Error\nMap is not surrounded by walls!\n"
# define FORBIDDEN_CHARACTERS "Error\nForbidden characters in your map!\n"
# define MANY_START "Error\nThere are more than one starting points!\n"
# define MANY_EXIT "Error\nThere are more than one exit points!\n"
# define NO_START "Error\nThere is no starting point in the map!\n"
# define NO_EXIT "Error\nThere is no exit point in the map!\n"
# define NO_COLLECTIBLES "Error\nThere are no collectibles!\n"

# define NO_VALID_PATH "Error\nThere is no valid path in the map!\n"

# define NO_GAME_INITIALIZATION "Error\nCould not initialize game!\n"
# define NO_WINDOW_CREATION "Error\nCould not create window!\n"
# define NO_IMAGE "Error\nCould not find image!\n"

# define EXIT_FILE "./assets/exit.xpm"
# define EMPTY_FILE "./assets/empty.xpm"
# define COLLECTIBLE_FILE "./assets/collectible.xpm"
# define PLAYER_FILE "./assets/player.xpm"
# define WALL_FILE "./assets/wall.xpm"

# define GAME_SUCCESS "You escaped!\n"
# define GAME_FAIL "You didn't collect all collectibles!\n"

typedef struct s_mchecker
{
	int			collectibles_count;
	int			start_count;
	int			exit_count;
}				t_mchecker;

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_map
{
	char		**grid;
	int			x_size;
	int			y_size;
	int			collectibles_count;
	t_position	start;
	t_position	exit;
}				t_map;

typedef struct s_player
{
	t_position	current;
	int			collectible_count;
	int			move_count;
}				t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*wall_image;
	void		*empty_image;
	void		*exit_image;
	void		*player_image;
	void		*collectible_image;
	t_map		*map;
	t_player	player;
}				t_data;

void			ft_handle_more_error(int error_code);
int				ft_handle_error(t_data *data, int error_code);
int				key_hook(int key_code, t_data *data);
void			ft_handle_collectible(t_data *data);
void			ft_handle_exit(t_data *data);
void			ft_free_map(t_data *data);
int				ft_handle_close(t_data *data);
void			ft_handle_current_position(t_data *data);
int				ft_initialize_game(t_data *data);
int				ft_get_images(t_data *data);
void			ft_render(t_data *data, void *img, int x, int y);
void			ft_draw_first_map(t_data *data);
void			ft_handle_key_w(t_data *data);
void			ft_handle_key_a(t_data *data);
void			ft_handle_key_s(t_data *data);
void			ft_handle_key_d(t_data *data);
int				ft_key_hook(int key_code, t_data *data);
int				ft_strlen_int(const char *str);
void			ft_initialize_checker(t_mchecker *checker);
int				ft_check_surround_wall(t_map *map, int y, int x);
int				ft_check_enough_elements(t_map *map, t_mchecker *checker);
int				ft_dimension_check(t_map *map, int fd);
int				ft_read_map(t_map *map, int fd);
int				ft_check_map_elements(t_map *map);
int				ft_check_elements(t_map *map, int y, int x,
					t_mchecker *checker);
int				ft_handle_map_checker(t_map *map, char *file);
char			**ft_duplicate_map(t_map *map);
int				ft_check_valid_path(char **grid, int y, int x);
int				ft_do_path_check(t_map *map);
t_data			*ft_initialize_data(t_data *data);
#endif
