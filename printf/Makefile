NAME = libftprintf.a 

CFLAGS = -Wall -Wextra -Werror

SRC = 	ft_putchar.c\
		ft_putstr.c\
		ft_putnbr.c\
		ft_putunsigned.c\
		ft_puthexa.c\
		ft_putadress.c\
		ft_printf.c\
		ft_format.c\
		flags_bonus.c\

BONUS = space_bonus.c\
		plus_bonus.c\
		hashmaj_bonus.c\
		hashmin_bonus.c

OBJ_M = $(SRC:.c=.o)

OBJ_B = $(BONUS:.c=.o)

INCLUDES = ft_printf.h ft_printf_bonus.h

all: $(NAME)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_M) $(OBJ_B)
	$(AR) rcs $(NAME) $(OBJ_M) $(OBJ_B)

clean:
	$(RM) $(OBJ_M) $(OBJ_B) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: all
