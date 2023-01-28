/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:49:23 by wewang            #+#    #+#             */
/*   Updated: 2022/11/23 12:27:32 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_handle_key_w(t_data *data)
{
	if (data->map->grid[data->player.current.y - 1]
		[data->player.current.x] != WALL)
	{
		ft_render(data, data->empty_image, data->player.current.x,
			data->player.current.y);
		data->player.current.y--;
		ft_render(data, data->player_image, data->player.current.x,
			data->player.current.y);
	}
}

void	ft_handle_key_a(t_data *data)
{
	if (data->map->grid[data->player.current.y][data->player.current.x
		- 1] != WALL)
	{
		ft_render(data, data->empty_image, data->player.current.x,
			data->player.current.y);
		data->player.current.x--;
		ft_render(data, data->player_image, data->player.current.x,
			data->player.current.y);
	}
}

void	ft_handle_key_s(t_data *data)
{
	if (data->map->grid[data->player.current.y + 1]
		[data->player.current.x] != WALL)
	{
		ft_render(data, data->empty_image, data->player.current.x,
			data->player.current.y);
		data->player.current.y++;
		ft_render(data, data->player_image, data->player.current.x,
			data->player.current.y);
	}
}

void	ft_handle_key_d(t_data *data)
{
	if (data->map->grid[data->player.current.y][data->player.current.x
		+ 1] != WALL)
	{
		ft_render(data, data->empty_image, data->player.current.x,
			data->player.current.y);
		data->player.current.x++;
		ft_render(data, data->player_image, data->player.current.x,
			data->player.current.y);
	}
}

int	ft_key_hook(int key_code, t_data *data)
{
	if (key_code == KEY_W || key_code == KEY_A
		|| key_code == KEY_S || key_code == KEY_D)
	{
		if (key_code == KEY_W)
			ft_handle_key_w(data);
		else if (key_code == KEY_A)
			ft_handle_key_a(data);
		else if (key_code == KEY_S)
			ft_handle_key_s(data);
		else if (key_code == KEY_D)
			ft_handle_key_d(data);
		data->player.move_count++;
		ft_printf("Current move count: %d\n", data->player.move_count);
	}
	else if (key_code == KEY_ESC)
		ft_handle_close(data);
	ft_handle_current_position(data);
	return (1);
}
