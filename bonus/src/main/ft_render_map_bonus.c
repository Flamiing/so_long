/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:35:11 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/25 16:12:44 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>
#include <libft.h>
#include <mlx.h>
#include <stdbool.h>

void	ft_render_floor(t_game *game, t_position *pos)
{
	void	*img;
	int		w;
	int		h;

	img = mlx_xpm_file_to_image(game->mlx, "./textures/floor.xpm", &w, &h);
	if (!img)
		ft_exit_program(ERROR_IMG_READING, NO_MAP, game);
	if (pos)
	{
		mlx_put_image_to_window(game->mlx, game->window, img,
			pos->x * 16, pos->y * 16);
		return ;
	}
	ft_render_floor_2(game, img, 0, 0);
}

static void	ft_render_walls(t_game *game)
{
	void	*img;
	int		w;
	int		h;
	int		y;
	int		x;

	img = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm", &w, &h);
	if (!img)
		ft_exit_program(ERROR_IMG_READING, NO_MAP, game);
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == WALL || game->map->map[y][x] == EXIT)
				mlx_put_image_to_window(game->mlx, game->window,
					img, x * 16, y * 16);
			x++;
		}
		y++;
	}
}

static void	ft_render_items(t_game *game)
{
	void	*img;
	int		w;
	int		h;
	int		y;
	int		x;

	img = mlx_xpm_file_to_image(game->mlx, "./textures/chest.xpm", &w, &h);
	if (!img)
		ft_exit_program(ERROR_IMG_READING, NO_MAP, game);
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == ITEM)
				mlx_put_image_to_window(game->mlx, game->window,
					img, x * 16, y * 16);
			x++;
		}
		y++;
	}
}

void	ft_render_exit(t_game *game)
{
	void	*img;
	int		w;
	int		h;
	int		y;
	int		x;

	img = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm", &w, &h);
	if (!img)
		ft_exit_program(ERROR_IMG_READING, NO_MAP, game);
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == EXIT)
				mlx_put_image_to_window(game->mlx, game->window,
					img, x * 16, y * 16);
			x++;
		}
		y++;
	}
	game->exit_open = true;
}

void	ft_render_map(t_game *game)
{
	ft_render_floor(game, NULL);
	ft_render_walls(game);
	ft_render_items(game);
	ft_render_player(game);
	ft_render_enemy(game);
}
