/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:33:11 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/26 13:01:10 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <libft.h>
#include <mlx.h>
#include <stdbool.h>

void	ft_render_player(t_game *game)
{
	void	*img;
	int		w;
	int		h;
	int		y;
	int		x;

	img = mlx_xpm_file_to_image(game->mlx,
			"./textures/char_idle_down.xpm", &w, &h);
	if (!img)
		ft_exit_program(ERROR_IMG_READING, NO_MAP, game);
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == PLAYER)
				mlx_put_image_to_window(game->mlx, game->window,
					img, x * 16, y * 16);
			x++;
		}
		y++;
	}
}

void	ft_render_floor_2(t_game *game, void *img, int y, int x)
{
	y = 0;
	while (y < game->win_height)
	{
		x = 0;
		while (x < game->win_width)
		{
			mlx_put_image_to_window(game->mlx, game->window, img, x, y);
			x += 16;
		}
		y += 16;
	}
}
