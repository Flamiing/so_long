/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:34:14 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/25 11:24:51 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <libft.h>
#include <stdlib.h>

t_position	*ft_initialize_position(t_map *map, int search)
{
	int			y;	
	int			x;
	t_position	*pos;

	pos = (t_position *)malloc(sizeof(t_position));
	if (!pos)
		ft_exit_program(ERROR_MALLOC, map, NO_GAME);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == search)
			{
				pos->y = y;
				pos->x = x;
				return (pos);
			}
			x++;
		}
		y++;
	}
	return (pos);
}

t_position	*ft_initialize_defined_pos(t_game *game, int y, int x)
{
	t_position	*pos;

	pos = (t_position *)malloc(sizeof(t_position));
	if (!pos)
		ft_exit_program(ERROR_MALLOC, NO_MAP, game);
	pos->y = y;
	pos->x = x;
	return (pos);
}
