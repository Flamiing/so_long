/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parser_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:36:03 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/25 16:12:30 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>
#include <libft.h>

t_map	*ft_map_parser(char *filename)
{
	t_map	*map;

	map = NULL;
	map = ft_initialize_map(map, filename);
	if (!map)
		ft_exit_program(INVALID_MAP, NO_MAP, NO_GAME);
	ft_map_valid(map);
	return (map);
}
