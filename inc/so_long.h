/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:51:05 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/26 13:29:13 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <libft.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>

/* |~~~ POSITION STRUCT~~~| */
typedef struct s_position
{
	int	y;
	int	x;
}	t_position;

/* |~~~ MAP STRUCT~~~| */
typedef struct s_map
{
	int			fd;
	char		**map;
	char		**map_cpy;
	int			width;
	int			height;
	t_position	*player;
	t_position	*exit;
}	t_map;

/* |~~~ GAME STRUCT~~~| */
typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		win_width;
	int		win_height;
	size_t	steps;
	int		items;
	bool	exit_open;
	t_map	*map;
}	t_game;

/* |~~~ GENERAL ~~~| */
# define NO_GAME NULL
# define NO_MAP NULL
/* |~~~ HOOKS ~~~| */
# define ON_DESTROY 17
# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
/* |~~~ MAP ~~~| */
# define EMPTY 48
# define WALL 49
# define ITEM 67
# define EXIT 69
# define PLAYER 80
/* |~~~ ASSETS ~~~| */
# define C_WALK_UP "./textures/char_walk_up.xpm"
# define C_WALK_DOWN "./textures/char_walk_down.xpm"
# define C_WALK_LEFT "./textures/char_walk_left.xpm"
# define C_WALK_RIGHT "./textures/char_walk_right.xpm"
# define C_IDLE_UP "./textures/char_idle_up.xpm"
# define C_IDLE_DOWN "./textures/char_idle_down.xpm"
# define C_IDLE_LEFT "./textures/char_idle_left.xpm"
# define C_IDLE_RIGHT "./textures/char_idle_right.xpm"
/* |~~~ ERROR MESSAGES ~~~| */
# define ERROR_DUP "The map has a duplicated exit or initial position\n"
# define ERROR_LACK "The map lacks an exit, an item or an initial position\n"
# define ERROR_SHAPE "The map has wrong shape\n"
# define ERROR_EMPTY "The map is empty\n"
# define ERROR_NOWALL "The map lacks a wall\n"
# define ERROR_NOPATH "The map lacks a valid path\n"
# define INVALID_MAP "Map is invalid or couldn't get initialized\n"
# define WRONG_NUM_ARGUMENTS "Invalid number of arguments\n"
# define INVALID_ARGUMENT "Invalid argument\n"
# define ERROR_MALLOC "There was an error allocating memory\n"
# define ERROR_IMG_READING "Image reading has failed\n"
# define ERROR_LIST "The enemies list initialization failed\n"

/* |~~~ PROTOTYPES ~~~| */
void		ft_free_array(char **arr);
void		ft_how_to_use(int count);
void		ft_free_map(t_map *map);
void		ft_print_error(char *error);
void		ft_game_won(t_game *game);
void		ft_free_game(t_game *game);
void		ft_game_over(t_game *game);
void		ft_render_exit(t_game *game);
void		ft_render_map(t_game *game);
void		ft_render_game(t_game *game);
void		ft_render_player(t_game *game);
void		ft_steps_to_window(t_game *game);
void		ft_render_floor(t_game *game, t_position *pos);
void		ft_render_floor_2(t_game *game, void *img, int y, int x);
void		ft_exit_program(char *error_msg, t_map *map, t_game *game);
void		ft_player_move_up_2(t_game *game, t_position *player, void *img);
void		ft_player_move_left_2(t_game *game, t_position *player, void *img);
void		ft_player_move_right_2(t_game *game, t_position *player, void *img);
void		ft_player_move_down_2(t_game *game, t_position *player, void *img);

ssize_t		ft_nbr_lines(char *filename);

int			ft_valid_input(char *str);
int			ft_map_valid(t_map *map);
int			ft_count_items(t_map *map);
int			ft_close_game(t_game *game);
int			ft_invalid_elements(t_map *map);
int			ft_missing_valid_path(t_map *map);
int			ft_move_player(int keycode, t_game *game);

t_map		*ft_map_parser(char *filename);
t_map		*ft_initialize_map(t_map *map, char *filename);

t_game		*ft_initialize_game(t_map *map);

t_position	*ft_initialize_position(t_map *map, int search);
t_position	*ft_initialize_defined_pos(t_game *game, int y, int x);

#endif
