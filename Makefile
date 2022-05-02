NAME = so_long

HEADER = $(wildcard *.h)

SRC_FILE = $(wildcard *.c)

DST = $(SRC_FILE:.c=.o)

MLX_A = mlx/libmlx.a

PRINTF_A = ft_printf/libftprintf.a

CFLAGS = -Imlx

CC = gcc

all: $(NAME)

	
$(NAME): $(DST)
	make -C mlx
	make -C ft_printf
	$(CC) $(DST) $(MLX_A) $(PRINTF_A) -g -fsanitize=address -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %c $(HEADER) $(LIB_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C mlx
	make clean -C ft_printf
	rm -f $(DST)

fclean : clean
		make fclean -C ft_printf
		rm -f $(NAME) 
re : fclean all

.PHONY : all clean fclean re 