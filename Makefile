# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 14:39:20 by hugo-mar          #+#    #+#              #
#    Updated: 2025/04/01 17:43:12 by hugo-mar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

ARCHIVE = cub3d.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -O3 -I/usr/include -Iminilibx-linux \
         -Isources -Iget_next_line
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

MAKE_LIB = ar -rcs

SRCS_DIR = sources
GNL_DIR = get_next_line
MLX_DIR = minilibx-linux

SRCS = $(SRCS_DIR)/cub3d.c $(SRCS_DIR)/init.c \
	   $(SRCS_DIR)/mlx_fts1.c $(SRCS_DIR)/mlx_fts2.c \
	   $(SRCS_DIR)/raycasting.c $(SRCS_DIR)/tmp.c \
	   $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(ARCHIVE): $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(ARCHIVE)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
