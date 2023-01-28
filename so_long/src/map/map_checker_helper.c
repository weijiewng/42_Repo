/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:22:48 by wewang            #+#    #+#             */
/*   Updated: 2022/11/23 12:28:03 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_strlen_int(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_initialize_checker(t_mchecker *checker)
{
	checker->collectibles_count = 0;
	checker->exit_count = 0;
	checker->start_count = 0;
}

int	ft_check_surround_wall(t_map *map, int y, int x)
{
	if (y == 0 || y == map->y_size - 1 || x == 0 || x == map->x_size - 1)
	{
		if (map->grid[y][x] == WALL)
			return (1);
		return (-4);
	}
	return (1);
}

int	ft_check_enough_elements(t_map *map, t_mchecker *checker)
{
	map->collectibles_count = checker->collectibles_count;
	if (map->start.x == 0 && map->start.y == 0)
		return (-8);
	else if (map->exit.x == 0 && map->exit.y == 0)
		return (-9);
	else if (map->collectibles_count < 1)
		return (-10);
	return (1);
}
