/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 02:51:42 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/25 16:12:14 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>
#include <libft.h>
#include <stdbool.h>

int	ft_is_blocked(t_game *game, t_position *enemy)
{
	if ((game->map->map[enemy->y][enemy->x + 1] == WALL
		|| game->map->map[enemy->y][enemy->x + 1] == ITEM)
			&& (game->map->map[enemy->y][enemy->x - 1] == WALL
				|| game->map->map[enemy->y][enemy->x - 1] == ITEM))
		return (1);
	return (0);
}

void	ft_enemy_move_left_2(t_game *game, t_position *enemy, void *img)
{
	ft_render_floor(game, enemy);
	game->map->map[enemy->y][enemy->x] = EMPTY;
	enemy->x--;
	mlx_put_image_to_window(game->mlx, game->window,
		img, enemy->x * 16, enemy->y * 16);
	if (game->map->player->y == enemy->y
		&& game->map->player->x == enemy->x)
		game->alive = false;
	game->map->map[enemy->y][enemy->x] = ENEMY;
}
