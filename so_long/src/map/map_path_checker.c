/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:21:53 by wewang            #+#    #+#             */
/*   Updated: 2022/11/23 12:12:13 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	**ft_duplicate_map(t_map *map)
{
	char	**res;
	int		i;

	res = (char **)malloc(sizeof(char *) * (map->y_size + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (map->grid[i])
	{
		res[i] = ft_strdup(map->grid[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

int	ft_check_valid_path(char **grid, int y, int x)
{
	if (grid[y][x] == MAP_EXIT)
		return (1);
	if (grid[y][x] == COLLECTIBLE || grid[y][x] == EMPTY
		|| grid[y][x] == STARTING_POSITION)
	{
		grid[y][x] = '2';
		if (ft_check_valid_path(grid, y + 1, x) == 1)
			return (1);
		if (ft_check_valid_path(grid, y - 1, x) == 1)
			return (1);
		if (ft_check_valid_path(grid, y, x + 1) == 1)
			return (1);
		if (ft_check_valid_path(grid, y, x - 1) == 1)
			return (1);
	}
	return (-11);
}

void	ft_free_dup(char **dup)
{
	int	i;

	i = 0;
	while (dup[i])
	{
		free(dup[i]);
		i++;
	}
	free(dup);
}

int	ft_do_path_check(t_map *map)
{
	char	**dup;
	int		res;

	dup = ft_duplicate_map(map);
	if (dup == NULL)
		return (0);
	res = ft_check_valid_path(dup, map->start.y, map->start.x);
	ft_free_dup(dup);
	return (res);
}
