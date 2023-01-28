/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:27:53 by wewang            #+#    #+#             */
/*   Updated: 2022/11/23 12:14:03 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_initialize_game(t_data *data)
{
	int	res;

	res = 1;
	data->player.current = data->map->start;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (-12);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map->x_size * X_SIZE,
			data->map->y_size * Y_SIZE, "42 So Long Game");
	if (data->win_ptr == NULL)
		return (-13);
	res = ft_get_images(data);
	if (res == -14)
		return (res);
	ft_draw_first_map(data);
	return (res);
}

int	ft_get_images(t_data *data)
{
	int	img_width;
	int	img_height;

	data->exit_image = mlx_xpm_file_to_image(data->mlx_ptr, EXIT_FILE,
			&img_width, &img_height);
	data->empty_image = mlx_xpm_file_to_image(data->mlx_ptr, EMPTY_FILE,
			&img_width, &img_height);
	data->collectible_image = mlx_xpm_file_to_image(data->mlx_ptr,
			COLLECTIBLE_FILE, &img_width, &img_height);
	data->player_image = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_FILE,
			&img_width, &img_height);
	data->wall_image = mlx_xpm_file_to_image(data->mlx_ptr, WALL_FILE,
			&img_width, &img_height);
	if (data->wall_image == NULL || data->empty_image == NULL
		|| data->collectible_image == NULL || data->player_image == NULL
		|| data->wall_image == NULL)
		return (-14);
	return (1);
}
