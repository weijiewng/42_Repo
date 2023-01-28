/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:52:15 by wewang            #+#    #+#             */
/*   Updated: 2023/01/04 17:25:59 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_handle_collectible(t_data *data)
{
	data->map->grid[data->player.current.y][data->player.current.x] = EMPTY;
	data->player.collectible_count++;
}

void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map->grid)
	{
		while (i < data->map->y_size)
		{
			free(data->map->grid[i]);
			i++;
		}
		free(data->map->grid);
	}
	free(data->map);
}

int	ft_handle_close(t_data *data)
{
	if (data != NULL)
	{
		if (data->map != NULL)
			ft_free_map(data);
		if (data->mlx_ptr != NULL)
		{
			if (data->wall_image != NULL)
				mlx_destroy_image(data->mlx_ptr, data->wall_image);
			if (data->empty_image != NULL)
				mlx_destroy_image(data->mlx_ptr, data->empty_image);
			if (data->exit_image != NULL)
				mlx_destroy_image(data->mlx_ptr, data->exit_image);
			if (data->player_image != NULL)
				mlx_destroy_image(data->mlx_ptr, data->player_image);
			if (data->collectible_image != NULL)
				mlx_destroy_image(data->mlx_ptr, data->collectible_image);
			if (data->win_ptr != NULL)
				mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			mlx_destroy_display(data->mlx_ptr);
			free(data->mlx_ptr);
		}
		free(data);
	}
	exit(0);
}

void	ft_handle_exit(t_data *data)
{
	if (data->map->collectibles_count == data->player.collectible_count)
		ft_printf(GAME_SUCCESS);
	else
		ft_printf(GAME_FAIL);
	ft_handle_close(data);
}

void	ft_handle_current_position(t_data *data)
{
	char	current;

	current = data->map->grid[data->player.current.y][data->player.current.x];
	if (current == COLLECTIBLE)
		ft_handle_collectible(data);
	else if (current == MAP_EXIT)
		ft_handle_exit(data);
}
