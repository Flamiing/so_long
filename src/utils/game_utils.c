/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:37:24 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/26 13:02:13 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <libft.h>
#include <stdbool.h>
#include <stdlib.h>

int	ft_count_items(t_map *map)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == ITEM)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

t_game	*ft_initialize_game(t_map *map)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		ft_exit_program(ERROR_MALLOC, map, NO_GAME);
	game->mlx = NULL;
	game->window = NULL;
	game->win_width = map->width * 16;
	game->win_height = map->height * 16;
	game->steps = 0;
	game->items = ft_count_items(map);
	game->exit_open = false;
	game->map = map;
	return (game);
}
