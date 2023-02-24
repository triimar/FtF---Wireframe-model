# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 13:04:13 by tmarts            #+#    #+#              #
#    Updated: 2023/02/24 01:53:44 by tmarts           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
CC = gcc
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g3
LDFLAGS = -fsanitize=address -g3
LIBMLX	= ./MLX42
LIBFT	= ./libft
HEADERS	= -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS	= -lglfw -L /Users/$(USER)/homebrew/Cellar/glfw/3.3.8/lib/ $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a 
SRC_DIR = ./src/
SRCS	= $(addprefix $(SRC_DIR)/, \
main.c \
initiate.c \
2d_converters.c \
color.c \
rotations.c \
 map_utils.c \
map.c \
draw_line.c \
draw.c \
hooks.c)

OBJS	= ${SRCS:.c=.o}

all: libft libmlx $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)

libmlx:
	@$(MAKE) -C $(LIBMLX)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) ${LDFLAGS}

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBMLX) fclean

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft
