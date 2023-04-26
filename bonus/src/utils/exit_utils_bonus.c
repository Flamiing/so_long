/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:15:53 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/26 23:10:16 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>
#include <libft.h>
#include <stdlib.h>
#include <stdbool.h>

void	ft_game_won(t_game *game)
{
	ft_printf("\n\n");
	ft_printf("██╗   ██╗ ██████╗ ██╗   ██╗    ██╗    ██╗ ");
	ft_printf("██████╗ ███╗   ██╗██╗\n");
	ft_printf("╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║    ");
	ft_printf("██║██╔═══██╗████╗  ██║██║\n");
	ft_printf(" ╚████╔╝ ██║   ██║██║   ██║    ██║ █╗ ");
	ft_printf("██║██║   ██║██╔██╗ ██║██║\n");
	ft_printf("  ╚██╔╝  ██║   ██║██║   ██║    ██║███╗██║██║");
	ft_printf("   ██║██║╚██╗██║╚═╝\n");
	ft_printf("   ██║   ╚██████╔╝╚██████╔╝    ");
	ft_printf("╚███╔███╔╝╚██████╔╝██║ ╚████║██╗\n");
	ft_printf("   ╚═╝    ╚═════╝  ╚═════╝      ");
	ft_printf("╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═══╝╚═╝\n");
	ft_printf("\n\n");
	ft_close_game(game);
}

void	ft_game_over(t_game *game)
{
	ft_printf("\n\n");
	ft_printf("▄████  ▄▄▄       ███▄ ▄███▓▓█████     ");
	ft_printf("▒█████   ██▒   █▓▓█████  ██▀███  \n");
	ft_printf("██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ");
	ft_printf("▀    ▒██▒  ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒\n");
	ft_printf("▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███");
	ft_printf("      ▒██░  ██▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒\n");
	ft_printf("░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄    ");
	ft_printf("▒██   ██░  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄  \n");
	ft_printf("░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒");
	ft_printf("   ░ ████▓▒░   ▒▀█░  ░▒████▒░██▓ ▒██▒\n");
	ft_printf(" ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░   ");
	ft_printf("░ ▒░▒░▒░    ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░\n");
	ft_printf("  ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░     ");
	ft_printf("░ ▒ ▒░    ░ ░░   ░ ░  ░  ░▒ ░ ▒░\n");
	ft_printf("░ ░   ░   ░   ▒   ░      ░      ░      ");
	ft_printf("░ ░ ░ ▒       ░░     ░     ░░   ░ \n");
	ft_printf("      ░       ░  ░       ░      ░  ");
	ft_printf("░       ░ ░        ░     ░  ░   ░     \n");
	ft_printf("                                           ");
	ft_printf("          ░                   \n");
	ft_printf("\n\n");
	ft_close_game(game);
}

int	ft_close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	ft_free_game(game);
	exit(EXIT_SUCCESS);
}

void	ft_how_to_use(int count)
{
	if (count == 2)
		ft_print_error(INVALID_ARGUMENT);
	else
		ft_print_error(WRONG_NUM_ARGUMENTS);
	exit(EXIT_FAILURE);
}

void	ft_exit_program(char *error_msg, t_map *map, t_game *game)
{
	if (game)
		ft_free_game(game);
	else if (map)
		ft_free_map(map);
	if (!error_msg)
		write(2, "Error\n", 6);
	else
		ft_print_error(error_msg);
	exit(EXIT_FAILURE);
}
