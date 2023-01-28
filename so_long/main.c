/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:12:04 by wewang            #+#    #+#             */
/*   Updated: 2022/11/23 12:22:17 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*ft_initialize_data(t_data *data)
{
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->map = (t_map *)malloc(sizeof(t_map));
	if (data->map == NULL)
		return (NULL);
	data->map->x_size = 0;
	data->map->y_size = 0;
	data->map->collectibles_count = 0;
	data->player.collectible_count = 0;
	data->player.move_count = 0;
	data->wall_image = NULL;
	data->empty_image = NULL;
	data->exit_image = NULL;
	data->player_image = NULL;
	data->collectible_image = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	return (data);
}

int	main(int argc, char *argv[])
{
	t_data	*data;
	int		res;

	res = -15;
	data = NULL;
	if (argc == 2)
	{
		data = ft_initialize_data(data);
		if (data == NULL)
			return (ft_handle_error(data, res));
		res = ft_handle_map_checker(data->map, argv[1]);
		if (res <= 0)
			return (ft_handle_error(data, res));
		res = ft_initialize_game(data);
		if (res <= 0)
			return (ft_handle_error(data, res));
		mlx_key_hook(data->win_ptr, &ft_key_hook, data);
		mlx_hook(data->win_ptr, 17, 0, &ft_handle_close, data);
		mlx_loop(data->mlx_ptr);
	}
	else
		return (ft_handle_error(data, res));
	return (1);
}
