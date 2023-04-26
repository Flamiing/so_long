/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:14:04 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/25 17:14:00 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>
#include <libft.h>
#include <stdbool.h>

static void	ft_move_right_2(t_game *game, t_position *enemy, void *img)
{
	ft_render_floor(game, enemy);
	game->map->map[enemy->y][enemy->x] = EMPTY;
	enemy->x++;
	mlx_put_image_to_window(game->mlx, game->window,
		img, enemy->x * 16, enemy->y * 16);
	if (game->map->player->y == enemy->y
		&& game->map->player->x == enemy->x)
		game->alive = false;
	game->map->map[enemy->y][enemy->x] = ENEMY;
}

static void	ft_move_right(t_game *game, t_position *enemy, int keycode)
{
	static int	count;
	void		*img;
	int			w;
	int			h;

	if (game->map->map[enemy->y][enemy->x + 1] != WALL
		|| game->map->map[enemy->y][enemy->x + 1] != ITEM
		|| game->map->map[enemy->y][enemy->x + 1] != EXIT)
	{
		if (!count)
			count = 2;
		if (count % 2 == 0)
			img = mlx_xpm_file_to_image(game->mlx, E_WALK_RIGHT, &w, &h);
		else
			img = mlx_xpm_file_to_image(game->mlx, E_IDLE_RIGHT, &w, &h);
		if (!img)
			ft_exit_program(ERROR_IMG_READING, NO_MAP, game);
		if (game->map->map[enemy->y][enemy->x + 1] == PLAYER
			&& keycode != D_KEY)
			return ;
		ft_move_right_2(game, enemy, img);
		count++;
	}
}

static void	ft_move_left(t_game *game, t_position *enemy, int keycode)
{
	static int	count;
	void		*img;
	int			w;
	int			h;

	if (game->map->map[enemy->y][enemy->x - 1] != WALL
		|| game->map->map[enemy->y][enemy->x - 1] != ITEM
		|| game->map->map[enemy->y][enemy->x - 1] != EXIT
		|| game->map->map[enemy->y][enemy->x - 1] != PLAYER)
	{
		if (!count)
			count = 2;
		if (count % 2 == 0)
			img = mlx_xpm_file_to_image(game->mlx, E_WALK_LEFT, &w, &h);
		else
			img = mlx_xpm_file_to_image(game->mlx, E_IDLE_LEFT, &w, &h);
		if (!img)
			ft_exit_program(ERROR_IMG_READING, NO_MAP, game);
		if (game->map->map[enemy->y][enemy->x - 1] == PLAYER
			&& keycode != A_KEY)
			return ;
		ft_enemy_move_left_2(game, enemy, img);
		count++;
	}
}

static void	ft_move(t_game *game, t_enemy *enemy, int keycode)
{
	if (game->map->map[enemy->pos->y][enemy->pos->x - 1] == WALL
		|| game->map->map[enemy->pos->y][enemy->pos->x - 1] == ITEM
		|| game->map->map[enemy->pos->y][enemy->pos->x - 1] == ENEMY)
		enemy->direction = RIGHT;
	if (game->map->map[enemy->pos->y][enemy->pos->x + 1] == WALL
		|| game->map->map[enemy->pos->y][enemy->pos->x + 1] == ITEM
		|| game->map->map[enemy->pos->y][enemy->pos->x + 1] == ENEMY)
		enemy->direction = LEFT;
	if (enemy->direction == RIGHT)
	{
		if (game->map->map[enemy->pos->y][enemy->pos->x + 1] == EMPTY
				|| game->map->map[enemy->pos->y][enemy->pos->x + 1] == PLAYER)
			ft_move_right(game, enemy->pos, keycode);
	}
	else if (enemy->direction == LEFT)
	{
		if (game->map->map[enemy->pos->y][enemy->pos->x - 1] == PLAYER
			|| game->map->map[enemy->pos->y][enemy->pos->x - 1] == EMPTY)
			ft_move_left(game, enemy->pos, keycode);
	}
}

void	ft_move_enemy(t_game *game, int keycode)
{
	t_enemy	*enemy;

	enemy = game->enemy;
	while (enemy != NULL)
	{
		if (enemy->wait == false)
		{
			ft_move(game, enemy, keycode);
			enemy->wait = true;
		}
		enemy = enemy->next;
	}
}
