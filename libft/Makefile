# **************************************************************************** #
#																			  #
#														 :::	  ::::::::	#
#	Makefile										   :+:	  :+:	:+:	#
#													 +:+ +:+		 +:+	  #
#	By: divalent <divalent@student.42.fr>		  +#+  +:+	   +#+		 #
#												 +#+#+#+#+#+   +#+			#
#	Created: 2023/10/17 13:04:56 by divalent		  #+#	#+#			  #
#	Updated: 2023/10/18 15:07:20 by divalent		 ###   ########.fr		#
#																			  #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c ft_strchr.c \
ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strdup.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_calloc.c  \
get_next_line_bonus.c get_next_line_utils_bonus.c

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

NAME = libft.a

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

bonus: $(BONUS_OBJ)
	@ar rcs $(NAME) $(BONUS_OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re