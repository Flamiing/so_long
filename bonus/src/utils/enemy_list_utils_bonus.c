/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_list_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:57:45 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/25 16:12:17 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>
#include <libft.h>
#include <stdbool.h>
#include <stdlib.h>

static t_enemy	*ft_listlast(t_enemy *enemy)
{
	if (!enemy)
		return (NULL);
	while (enemy->next != NULL)
		enemy = enemy->next;
	return (enemy);
}

static void	ft_listadd_back(t_enemy **enemy, t_enemy *new)
{
	t_enemy	*last;

	if (*enemy == NULL)
		*enemy = new;
	else
	{
		last = ft_listlast(*enemy);
		last->next = new;
	}
}

static t_enemy	*ft_newnode(t_position *enemy)
{
	t_enemy	*node;

	node = (t_enemy *)malloc(sizeof(t_enemy));
	if (!node)
		return (0);
	node->pos = enemy;
	node->wait = true;
	node->direction = RIGHT;
	node->next = NULL;
	return (node);
}

t_enemy	*ft_initialize_enemy(t_game *game, int y, int x)
{
	t_enemy	*head;
	t_enemy	*enemy;

	head = NULL;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == ENEMY)
			{
				enemy = ft_newnode(ft_initialize_defined_pos(game, y, x));
				if (!enemy)
					ft_exit_program(ERROR_LIST, NO_MAP, game);
				if (head == NULL)
					head = enemy;
				else
					ft_listadd_back(&head, enemy);
			}
			x++;
		}
		y++;
	}
	return (head);
}
