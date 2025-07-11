SRCS = ft_atoi.c		ft_bzero.c		ft_calloc.c		ft_isalnum.c	ft_isalpha.c	ft_isascii.c	\
	   ft_isdigit.c		ft_isprint.c	ft_itoa.c		ft_memchr.c		ft_memcmp.c		ft_memcpy.c		\
	   ft_memmove.c		ft_memset.c		ft_putchar_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c					\
	   ft_putstr_fd.c	ft_split.c		ft_strchr.c		ft_strdup.c		ft_striteri.c	ft_strjoin.c	\
	   ft_strlcat.c		ft_strlcpy.c	ft_strlen.c		ft_strmapi.c	ft_strncmp.c					\
	   ft_strnstr.c		ft_strrchr.c	ft_strtrim.c	ft_substr.c		ft_tolower.c	ft_toupper.c	\
	   get_next_line_bonus.c	get_next_line_utils_bonus.c	ft_count_words.c	ft_free_2arr.c			\
	   ft_atoi_base.c	ft_strtoupper.c

BONS = ft_lstadd_back.c	ft_lstadd_front.c	ft_lstclear.c	ft_lstdelone.c	ft_lstiter.c	\
	   ft_lstlast.c		ft_lstmap.c			ft_lstnew.c		ft_lstsize.c	ft_printlst.c

OBJS = $(SRCS:%.c=%.o)
BONS_OBJS = $(BONS:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $@ $^
	@echo "libft build complete."

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONS_OBJS)
	@ar -rcs $(NAME) $^

clean:
	@rm -f $(OBJS) $(BONS_OBJS)
	@echo "libft object files removed."

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) removed."

re: fclean all

.PHONY: all clean fclean re bonus

