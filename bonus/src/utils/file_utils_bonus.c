/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:35 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/25 16:11:59 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>
#include <libft.h>
#include <fcntl.h>

ssize_t	ft_nbr_lines(char *filename)
{
	ssize_t	count;
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	close(fd);
	return (count);
}
