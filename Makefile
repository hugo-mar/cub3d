# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: divalent <divalent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 14:39:20 by hugo-mar          #+#    #+#              #
#    Updated: 2025/04/21 17:55:39 by divalent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC = $(addprefix ./sources/, $(SOURCES))
SOURCES = cub3d.c init.c mlx_fts1.c mlx_fts2.c raycasting1.c raycasting2.c movement1.c movement2.c \
		textures1.c textures2.c tmp.c utils.c utils2.c map_maker.c check_map.c check_map2.c parsing.c \
		inputs.c minimap.c

MLX_LIB = ./minilibx-linux/libmlx_Linux.a
LIB = libftprintf/libftprintf.a libft/libft.a $(MLX_LIB)

OBJ = $(SRC:.c=.o)

all: libftprintf.a libft.a libmlx_linux.a $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ) libftprintf/libftprintf.a libft/libft.a $(MLX_LIB)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@
	@echo "cub3D built"

libftprintf.a:
	@make -C ./libftprintf

libft.a:
	@make -C ./libft

libmlx_linux.a:
	@make -C ./minilibx-linux/ -f Makefile.gen

clean:
	@rm -f $(OBJ)
	@make -C libftprintf clean
	@make -C libft clean
	@make -C ./minilibx-linux/ -f Makefile.gen clean

fclean: clean
	@rm -f $(NAME)
	@make -C libftprintf fclean
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re