# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akok <akok@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 15:54:33 by akok              #+#    #+#              #
#    Updated: 2025/07/11 08:59:16 by akok             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft

SRCS =	srcs/draw.c			\
		srcs/event_utils.c	\
		srcs/event.c		\
		srcs/fdf.c			\
		srcs/init.c			\
		srcs/interp.c		\
		srcs/parse_map.c	\
		srcs/render.c		\
		srcs/transform.c	\
		srcs/utils.c		\
		srcs/view.c

OBJS = $(SRCS:%.c=%.o)

LIB_PATH = ./libft
LIBFT = $(LIB_PATH)/libft.a

NAME = fdf

all: $(NAME) $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(LIBFT) -o $(NAME)
	@echo "$(NAME) built."
	
$(LIBFT):
	@make -C $(LIB_PATH) all
	@make -C $(LIB_PATH) bonus

%.o: %.c
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

bonus: all

clean:
	@rm -f $(OBJS)
	@make -C $(LIB_PATH) clean
	@echo "object files removed."
	
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "$(NAME) removed."

re: fclean all

.PHONY: all clean fclean re bonus
