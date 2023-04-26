/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:36:03 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/25 15:35:46 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
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
