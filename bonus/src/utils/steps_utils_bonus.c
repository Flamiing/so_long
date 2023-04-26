/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:18:47 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/25 16:11:11 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>
#include <libft.h>
#include <mlx.h>

static	size_t	ft_count_digits(long long n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_render_stepboard(t_game *game)
{
	void	*img;
	int		w;
	int		h;
	int		size;
	int		digits;

	img = mlx_xpm_file_to_image(game->mlx, "./textures/stepboard.xpm", &w, &h);
	if (!img)
		ft_exit_program(ERROR_IMG_READING, NO_MAP, game);
	size = 0;
	digits = ft_count_digits(game->steps);
	if (digits > 2)
		size += digits;
	mlx_put_image_to_window(game->mlx, game->window,
		img, size * 4, 0);
	mlx_put_image_to_window(game->mlx, game->window,
		img, 0, 0);
}

void	ft_steps_to_window(t_game *game)
{
	char	*count;

	ft_render_stepboard(game);
	count = ft_itoa(game->steps);
	if (!count)
		ft_exit_program(ERROR_MALLOC, NO_MAP, game);
	mlx_string_put(game->mlx, game->window, 0, 10, 0x00FFFFFF, count);
	free(count);
}
