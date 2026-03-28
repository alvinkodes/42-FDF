CC			= cc
CFLAGS		= -Werror -Wextra -Wall -g3 #-fsanitize=address
INC			= -I ./includes/\
			  -I ./libft/\
			  -I ./minilibx-linux/

NAME		= fdf

MLX_PATH	= minilibx-linux/
MLX			= $(MLX_PATH)libmlx_Linux.a

LIBFT_PATH	= libft/
LIBFT		= $(LIBFT_PATH)libft.a

#find . -type f -name "*.c" | sed 's|^\./||'
SRC_PATH = ./srcs/
SRC		= 	draw.c \
			event_utils.c \
			event.c \
			fdf.c \
			init.c \
			interp.c \
			parse_map.c \
			render.c \
			transform.c \
			utils.c \
			view.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH	= ./obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(OBJ_PATH) $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)
	mkdir -p $(OBJ_PATH)/exit
	mkdir -p $(OBJ_PATH)/image
	mkdir -p $(OBJ_PATH)/init
	mkdir -p $(OBJ_PATH)/input_n_movement
	mkdir -p $(OBJ_PATH)/memory	
	mkdir -p $(OBJ_PATH)/parsing
	mkdir -p $(OBJ_PATH)/rendering
	mkdir -p $(OBJ_PATH)/validation

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC) $(LIBFT) $(MLX) -lXext -lX11 -lm

$(LIBFT):
	make -sC $(LIBFT_PATH)

$(MLX):
	make -sC $(MLX_PATH)

clean:
	rm -rf $(OBJ_PATH)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all re clean fclean