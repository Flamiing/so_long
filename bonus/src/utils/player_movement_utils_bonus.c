/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_utils_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 03:17:10 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/25 16:11:26 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>
#include <libft.h>
#include <mlx.h>
#include <stdbool.h>

void	ft_player_move_up_2(t_game *game, t_position *player, void *img)
{
	if (game->map->map[player->y - 1][player->x] == ENEMY)
		game->alive = false;
	ft_render_floor(game, game->map->player);
	game->map->map[player->y][player->x] = EMPTY;
	player->y--;
	game->map->map[player->y][player->x] = PLAYER;
	mlx_put_image_to_window(game->mlx, game->window,
		img, player->x * 16, player->y * 16);
}

void	ft_player_move_down_2(t_game *game, t_position *player, void *img)
{
	if (game->map->map[player->y + 1][player->x] == ENEMY)
		game->alive = false;
	ft_render_floor(game, game->map->player);
	game->map->map[player->y][player->x] = EMPTY;
	player->y++;
	game->map->map[player->y][player->x] = PLAYER;
	mlx_put_image_to_window(game->mlx, game->window,
		img, player->x * 16, player->y * 16);
}

void	ft_player_move_left_2(t_game *game, t_position *player, void *img)
{
	if (game->map->map[player->y][player->x - 1] == ENEMY)
		game->alive = false;
	ft_render_floor(game, game->map->player);
	game->map->map[player->y][player->x] = EMPTY;
	player->x--;
	game->map->map[player->y][player->x] = PLAYER;
	mlx_put_image_to_window(game->mlx, game->window,
		img, player->x * 16, player->y * 16);
}

void	ft_player_move_right_2(t_game *game, t_position *player, void *img)
{
	if (game->map->map[player->y][player->x + 1] == ENEMY)
		game->alive = false;
	ft_render_floor(game, game->map->player);
	game->map->map[player->y][player->x] = EMPTY;
	player->x++;
	game->map->map[player->y][player->x] = PLAYER;
	mlx_put_image_to_window(game->mlx, game->window,
		img, player->x * 16, player->y * 16);
}
