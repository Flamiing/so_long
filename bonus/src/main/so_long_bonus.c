/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:32:19 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/25 16:12:51 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>
#include <mlx.h>
#include <libft.h>
#include <stdbool.h>

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	if (argc != 2 || !ft_valid_input(argv[1]))
		ft_how_to_use(argc);
	map = ft_map_parser(argv[1]);
	game = ft_initialize_game(map);
	ft_render_game(game);
	ft_free_game(game);
	return (0);
}
