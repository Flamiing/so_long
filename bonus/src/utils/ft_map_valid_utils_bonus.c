/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_valid_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:32:31 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/26 13:29:47 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>
#include <libft.h>

static int	ft_check_invalid_path(t_map *map, int y, int x, int search)
{
	if (search == EXIT)
	{
		y = map->exit->y;
		x = map->exit->x;
	}
	if (map->map_cpy[y - 1][x] == PLAYER
		|| map->map_cpy[y + 1][x] == PLAYER
		|| map->map_cpy[y][x - 1] == PLAYER
		|| map->map_cpy[y][x + 1] == PLAYER)
		return (0);
	return (1);
}

static int	ft_invalid_path_item(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == ITEM)
			{
				if (ft_check_invalid_path(map, y, x, ITEM))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static void	ft_floodfill(t_map *map, int y, int x)
{
	static size_t	iteration;

	if (!iteration)
		iteration = 0;
	iteration++;
	if (y < 0 || x < 0 || y >= map->height || x >= map->width
		|| (map->map_cpy[y][x] != EMPTY && iteration != 1))
		return ;
	if (map->map_cpy[y][x] == EMPTY)
		map->map_cpy[y][x] = PLAYER;
	ft_floodfill(map, y - 1, x);
	ft_floodfill(map, y + 1, x);
	ft_floodfill(map, y, x - 1);
	ft_floodfill(map, y, x + 1);
}

int	ft_missing_valid_path(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map_cpy[y][x] != WALL
				&& map->map_cpy[y][x] != PLAYER
				&& map->map_cpy[y][x] != ENEMY
				&& map->map_cpy[y][x] != EXIT)
				map->map_cpy[y][x] = EMPTY;
			x++;
		}
		y++;
	}
	ft_floodfill(map, map->player->y, map->player->x);
	if (ft_check_invalid_path(map, 0, 0, EXIT))
		return (1);
	if (ft_invalid_path_item(map))
		return (1);
	return (0);
}

int	ft_invalid_elements(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] != EMPTY &&
				map->map[y][x] != WALL &&
				map->map[y][x] != ITEM &&
				map->map[y][x] != EXIT &&
				map->map[y][x] != PLAYER &&
				map->map[y][x] != ENEMY)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
