NAME = pipex.a

CFLAGS = -Wall -Wextra -Werror

SRC = 	parssing.c\
		pipex_utils.c\

LIBFT = libft/libft.a

PRINTF = printf/libftprintf.a

PATH_LIBFT = /Users/ouakrad/Desktop/cursus/pipex/libft

PATH_PRINTF = /Users/ouakrad/Desktop/cursus/pipex/printf

OBJ = $(SRC:.c=.o)

INCLUDES = pipex.h

all: $(NAME)

${LIBFT}	:
				make -C ${PATH_LIBFT}

${PRINTF}	:
				make -C ${PATH_PRINTF}

%.o : %.c $(INCLUDES) ${LIBFT}${PRINTF}
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) ${LIBFT} ${PRINTF}
	$(AR) rcs $(NAME) $(OBJ) $(LIBFT) ${PRINTF}

clean:
	$(RM) $(OBJ)
	make clean -C ${PATH_LIBFT}
	make clean -C ${PATH_PRINTF}

fclean: clean
	$(RM) $(NAME)
	make fclean -C ${PATH_LIBFT}
	make fclean -C ${PATH_PRINTF}

re: fclean all

