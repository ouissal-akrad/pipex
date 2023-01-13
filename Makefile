NAME = pipex

CFLAGS = -Wall -Wextra -Werror

SRC = 	parssing.c\
		main.c \
		pipex.c\

LIBFT = libft/libft.a

PATH_LIBFT = libft

OBJ = $(SRC:.c=.o)

INCLUDES = pipex.h

all: $(NAME)

${LIBFT}	:
	make -C ${PATH_LIBFT}

%.o : %.c $(INCLUDES) ${LIBFT}
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) ${LIBFT}
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	$(RM) $(OBJ)
	make clean -C ${PATH_LIBFT}

fclean: clean
	$(RM) $(NAME)
	make fclean -C ${PATH_LIBFT}

re: fclean all
