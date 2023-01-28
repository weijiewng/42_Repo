/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:05:51 by wewang            #+#    #+#             */
/*   Updated: 2022/11/23 12:18:31 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_dimension_check(t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
		return (-1);
	while (line)
	{
		map->y_size++;
		if (map->x_size == 0)
			map->x_size = ft_strlen_int(line);
		if (map->x_size != ft_strlen_int(line))
			return (-3);
		free(line);
		line = get_next_line(fd);
	}
	if ((map->x_size > 3 && map->y_size < 4) || (map->y_size > 3
			&& map->x_size < 4) || map->x_size < 3 || map->y_size < 3)
		return (-2);
	return (1);
}

int	ft_read_map(t_map *map, int fd)
{
	char	*line;
	int		i;

	map->grid = (char **)malloc(sizeof(char *) * (map->y_size + 1));
	if (map->grid == NULL)
		return (0);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->grid[i] = line;
		i++;
		line = get_next_line(fd);
	}
	free(line);
	map->grid[i] = NULL;
	return (1);
}

int	ft_check_map_elements(t_map *map)
{
	int			i;
	int			j;
	int			check_result;
	t_mchecker	checker;

	ft_initialize_checker(&checker);
	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			check_result = ft_check_elements(map, i, j, &checker);
			if (check_result < 1)
				return (check_result);
			j++;
		}
		i++;
	}
	return (ft_check_enough_elements(map, &checker));
}

int	ft_check_elements(t_map *map, int y, int x, t_mchecker *checker)
{
	if (ft_check_surround_wall(map, y, x) == -4)
		return (-4);
	else if (map->grid[y][x] == STARTING_POSITION)
	{
		if (checker->start_count > 0)
			return (-6);
		map->start.y = y;
		map->start.x = x;
		checker->start_count++;
	}
	else if (map->grid[y][x] == MAP_EXIT)
	{
		if (checker->exit_count > 0)
			return (-7);
		map->exit.y = y;
		map->exit.x = x;
		checker->exit_count++;
	}
	else if (map->grid[y][x] == COLLECTIBLE)
		checker->collectibles_count++;
	else if (map->grid[y][x] == WALL || map->grid[y][x] == EMPTY)
		return (1);
	else
		return (-5);
	return (1);
}

int	ft_handle_map_checker(t_map *map, char *file)
{
	int	fd;
	int	res;

	fd = open(file, O_RDONLY);
	res = ft_dimension_check(map, fd);
	close(fd);
	if (res <= 0)
		return (res);
	fd = open(file, O_RDONLY);
	res = ft_read_map(map, fd);
	if (res <= 0)
		return (res);
	close(fd);
	res = ft_check_map_elements(map);
	if (res <= 0)
		return (res);
	res = ft_do_path_check(map);
	return (res);
}
