/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:46:13 by wewang            #+#    #+#             */
/*   Updated: 2022/11/23 10:54:27 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_render(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, x * X_SIZE, y
		* Y_SIZE);
}

void	ft_draw_first_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->y_size)
	{
		j = 0;
		while (j < data->map->x_size)
		{
			if (data->map->grid[i][j] == WALL)
				ft_render(data, data->wall_image, j, i);
			else if (data->map->grid[i][j] == COLLECTIBLE)
				ft_render(data, data->collectible_image, j, i);
			else if (data->map->grid[i][j] == STARTING_POSITION)
				ft_render(data, data->player_image, j, i);
			else if (data->map->grid[i][j] == MAP_EXIT)
				ft_render(data, data->exit_image, j, i);
			else if (data->map->grid[i][j] == EMPTY)
				ft_render(data, data->empty_image, j, i);
			j++;
		}
		i++;
	}
}
