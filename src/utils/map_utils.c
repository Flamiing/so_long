/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:44:21 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/25 15:43:42 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <libft.h>
#include <fcntl.h>
#include <stdlib.h>

static char	**ft_copy_map(t_map *map)
{
	char	**map_cpy;
	int		count;
	size_t	len;

	map_cpy = (char **)ft_calloc(map->height + 1, sizeof(char *));
	if (!map_cpy)
		return (NULL);
	count = 0;
	len = 0;
	while (count < map->height)
	{
		len = ft_strlen(map->map[count]) + 1;
		map_cpy[count] = (char *)ft_calloc(len, sizeof(char));
		if (!map_cpy[count])
		{
			ft_free_array(map_cpy);
			return (NULL);
		}
		ft_strlcpy(map_cpy[count], map->map[count], len);
		count++;
	}
	map_cpy[count] = 0;
	return (map_cpy);
}

static void	ft_get_map_size(t_map *map, int height)
{
	int	width;

	map->height = height;
	width = 0;
	if (!map->map[0])
	{
		map->width = 0;
		return ;
	}
	while (map->map[0][width])
		width++;
	map->width = width - 1;
}

static t_map	*ft_fillmap(t_map *map)
{
	size_t	count;
	char	*line;

	count = 0;
	line = get_next_line(map->fd);
	while (line)
	{
		map->map[count] = line;
		line = get_next_line(map->fd);
		count++;
	}
	return (map);
}

static char	**ft_getmap(t_map *map, char *filename)
{
	ssize_t	size;

	size = ft_nbr_lines(filename) + 1;
	if (size == -1)
		return (NULL);
	map->fd = open(filename, O_RDONLY);
	if (map->fd == -1)
		return (NULL);
	map->map = (char **)ft_calloc(size, sizeof(char *));
	if (!map->map)
	{
		close(map->fd);
		return (NULL);
	}
	map = ft_fillmap(map);
	ft_get_map_size(map, size - 1);
	close(map->fd);
	return (map->map);
}

t_map	*ft_initialize_map(t_map *map, char *filename)
{
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = 0;
	map->height = 0;
	map->map_cpy = NULL;
	map->player = NULL;
	map->exit = NULL;
	map->map = ft_getmap(map, filename);
	if (!map->map)
	{
		ft_free_map(map);
		return (NULL);
	}
	map->map_cpy = ft_copy_map(map);
	if (!map->map_cpy)
	{
		ft_free_map(map);
		return (NULL);
	}
	map->player = ft_initialize_position(map, PLAYER);
	map->exit = ft_initialize_position(map, EXIT);
	return (map);
}
