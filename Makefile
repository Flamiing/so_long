# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 20:45:55 by alaaouam          #+#    #+#              #
#    Updated: 2023/04/26 12:36:34 by alaaouam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	COLOURS	#

GREEN = \033[0:32m
COLOR_OFF = \033[0m

#	VARIABLES	#

NAME = so_long
NAME_BONUS = so_long_bonus

SRC = so_long.c ft_map_parser.c ft_map_valid.c error_utils.c exit_utils.c main_utils.c file_utils.c \
				free_utils.c map_utils.c ft_map_valid_utils.c position_utils.c game_utils.c ft_render_game.c \
				ft_render_map.c ft_render_map_utils.c player_movement.c player_movement_utils.c steps_utils.c

SRC_BONUS = so_long_bonus.c ft_map_parser_bonus.c ft_map_valid_bonus.c error_utils_bonus.c exit_utils_bonus.c \
								main_utils_bonus.c file_utils_bonus.c free_utils_bonus.c map_utils_bonus.c ft_map_valid_utils_bonus.c \
								position_utils_bonus.c game_utils_bonus.c ft_render_game_bonus.c ft_render_map_bonus.c ft_render_map_utils_bonus.c \
								player_movement_bonus.c enemy_list_utils_bonus.c enemy_movement_bonus.c enemy_movement_utils_bonus.c \
								player_movement_utils_bonus.c steps_utils_bonus.c

SRC_PATH = src/*/
SRCS = $(addprefix $(SRC_PATH), $(SRC))

SRC_BONUS_PATH = bonus/src/*/
SRCS_BONUS = $(addprefix $(SRC_BONUS_PATH), $(SRC_BONUS))

OBJ_PATH = obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

OBJ_BONUS_PATH = obj_bonus/
OBJ_BONUS = $(SRC_BONUS:.c=.o)
OBJS_BONUS = $(addprefix $(OBJ_BONUS_PATH), $(OBJ_BONUS))

LIBFT_PATH = lib/libft/
LIBFT = $(LIBFT_PATH)libft.a

MLX_PATH = lib/miniLibX/
MLX = $(MLX_PATH)libmlx.a

INCLUDE = inc/
INCLUDE_BONUS = bonus/inc/

CC = gcc
CFLAGS =  -Wall -Wextra -Werror -I $(INCLUDE) -I ./lib/libft/include -I ./lib/miniLibX
CFLAGS_BONUS =  -Wall -Wextra -Werror -I $(INCLUDE_BONUS) -I ./lib/libft/include -I ./lib/miniLibX -arch x86_64
LFLAGS =  -Lmlx -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

#	RULES	#

all: $(NAME)

$(LIBFT): $(LIBFT_PATH)
	@make -C $(LIBFT_PATH)
	
$(MLX): $(MLX_PATH)
	@make -C $(MLX_PATH)
	@mkdir -p mlx
	@cp $(MLX) mlx
	@echo "$(GREEN)<+> mlx has been created! <+>$(COLOR_OFF)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)
	@echo "$(GREEN)<+> so_long has been created! <+>$(COLOR_OFF)"

$(OBJ_BONUS_PATH)%.o: $(SRC_BONUS_PATH)%.c
	@mkdir -p $(OBJ_BONUS_PATH)
	$(CC) $(CFLAGS_BONUS) -c $< -o $@

$(NAME_BONUS): $(LIBFT) $(MLX) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX) -o $(NAME_BONUS)
	@echo "$(GREEN)<+> so_long_bonus has been created! <+>$(COLOR_OFF)"

bonus: $(NAME_BONUS)

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_PATH) clean
	@$(RM) mlx
	@echo "$(GREEN)<-> mlx cleaned successfuly! <->$(COLOR_OFF)"
	@$(RM) $(OBJ_PATH)
	@$(RM) $(OBJ_BONUS_PATH)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@echo "$(GREEN)<-> so_long cleaned successfuly! <->$(COLOR_OFF)"

re: fclean all

.PHONY: all clean fclean re bonus