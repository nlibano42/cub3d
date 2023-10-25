# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlibano- <nlibano-@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 12:26:49 by ruramire          #+#    #+#              #
#    Updated: 2023/10/25 23:40:40 by nlibano-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	cub3D
SRC				=	src/main.c								\
					src/check/check.c						\
					src/check/check_colors.c				\
					src/check/check_colors_utils.c			\
					src/check/check_textures.c				\
					src/check/check_textures_utils.c		\
					src/check/check_map.c					\
					src/check/check_characters.c			\
					src/check/check_map_add_space.c			\
					src/check/check_valid_map.c				\
					src/check/check_wall.c					\
					src/check/middle_char.c					\
					src/free/free.c							\
					src/gnl/get_next_line.c					\
					src/gnl/get_next_line_utils.c			\
					src/mlx/mlx_key.c						\
					src/mlx/mlx_init.c						\
					src/mlx/mlx_actions.c					\
					src/parsing/parsing.c					\
					src/parsing/get_all.c					\
					src/parsing/parsing_utils.c				\
					src/raycasting/rendering.c				\
					src/raycasting/geometry.c				\
					src/raycasting/textures_and_player.c	\
					src/raycasting/intersections_vertical.c	\
					src/raycasting/intersections_horizontal.c

OBJ 			= 	$(SRC:.c=.o)
CC 				=	gcc
CFLAGS 			= 	-Wall -Wextra -Werror -Imlx -g #-fsanitize=address -g3 
MLXFLAGS 		= 	-Lmlx -lmlx -framework OpenGL -framework AppKit
MLX_LIB 		= 	mlx/libmlx.a
LIBFT_LIB 		= 	utils/libft/libft.a

.SILENT:

all: $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):$(MLX_LIB) $(LIBFT_LIB) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) $(MLXFLAGS) $(MLX_LIB) -o $(NAME)
	@echo "cub3D compilated: : ./cub3D map/map.cub"

$(LIBFT_LIB):$(LIBFT_HEADER)
	@make -C utils/libft/

$(MLX_LIB):
	@make -C mlx 2> /dev/null

clean:
	@rm -rf $(OBJ)
	@make fclean -C utils/libft
	@make clean -C mlx
	@echo ".o files deleted"

fclean: clean
	@rm -rf $(NAME)
	@echo "cub3D deleted"

re: fclean all

play: all
	@echo "running cub3D ..."
	@./cub3D map/map.cub

.PHONY: all fclean clean re play
