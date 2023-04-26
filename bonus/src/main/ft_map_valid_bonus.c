/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_valid_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:13:41 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/25 16:12:34 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>
#include <libft.h>

static int	ft_missing_wall(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->width)
	{
		if (map->map[0][x] != WALL)
			return (1);
		if (map->map[map->height - 1][x] != WALL)
			return (1);
		x++;
	}
	y = 0;
	while (y < map->height)
	{
		if (map->map[y][0] != WALL)
			return (1);
		if (map->map[y][map->width - 1] != WALL)
			return (1);
		y++;
	}
	return (0);
}

static int	ft_invalid_shape(t_map *map, int x, int y)
{
	if (map->width == map->height)
		return (1);
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x] && map->map[y][x] != '\n')
			x++;
		if (x != map->width)
			return (1);
		y++;
	}
	x = 0;
	while (map->map[0][x])
	{
		y = 0;
		while (map->map[y])
			y++;
		if (y != map->height)
			return (1);
		x++;
	}
	return (0);
}

static int	ft_lacks_necessary_stuff(t_map *map, int y, int x)
{
	size_t	exit_count;
	size_t	player_count;
	size_t	item_count;

	exit_count = 0;
	player_count = 0;
	item_count = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == EXIT)
				exit_count++;
			if (map->map[y][x] == PLAYER)
				player_count++;
			if (map->map[y][x] == ITEM)
				item_count++;
			x++;
		}
		y++;
	}
	if (exit_count < 1 || player_count < 1 || item_count < 1)
		return (1);
	return (0);
}

static int	ft_dup_exit_or_player(t_map *map)
{
	int		x;
	int		y;
	size_t	exit_count;
	size_t	player_count;

	y = 0;
	exit_count = 0;
	player_count = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == EXIT)
				exit_count++;
			if (map->map[y][x] == PLAYER)
				player_count++;
			x++;
		}
		y++;
	}
	if (exit_count > 1 || player_count > 1)
		return (1);
	return (0);
}

int	ft_map_valid(t_map *map)
{
	if (map->width == 0 && map->height == 0)
		ft_exit_program(ERROR_EMPTY, map, NO_GAME);
	else if (ft_invalid_shape(map, 0, 0))
		ft_exit_program(ERROR_SHAPE, map, NO_GAME);
	else if (ft_invalid_elements(map))
		ft_exit_program(INVALID_MAP, map, NO_GAME);
	else if (ft_dup_exit_or_player(map))
		ft_exit_program(ERROR_DUP, map, NO_GAME);
	else if (ft_lacks_necessary_stuff(map, 0, 0))
		ft_exit_program(ERROR_LACK, map, NO_GAME);
	else if (ft_missing_wall(map))
		ft_exit_program(ERROR_NOWALL, map, NO_GAME);
	else if (ft_missing_valid_path(map))
		ft_exit_program(ERROR_NOPATH, map, NO_GAME);
	return (1);
}
