/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:41:55 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/25 16:11:55 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>
#include <libft.h>
#include <stdbool.h>

void	ft_free_array(char **arr)
{
	int	index;

	index = 0;
	if (!arr)
		return ;
	while (arr[index])
	{
		free(arr[index]);
		index++;
	}
	free(arr[index]);
	free(arr);
}

void	ft_free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->map)
		ft_free_array(map->map);
	if (map->map_cpy)
		ft_free_array(map->map_cpy);
	if (map->player)
		free(map->player);
	if (map->exit)
		free(map->exit);
	free(map);
}

void	ft_free_game(t_game *game)
{
	if (!game)
		return ;
	ft_free_map(game->map);
	if (game->enemy)
		ft_free_list(&game->enemy);
	free(game);
}

void	ft_free_list(t_enemy **enemy)
{
	t_enemy	*temp;

	if (*enemy == NULL)
		return ;
	while (*enemy != NULL)
	{
		temp = *enemy;
		*enemy = temp->next;
		free(temp);
	}
	*enemy = NULL;
}
