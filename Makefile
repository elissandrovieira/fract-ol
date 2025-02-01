CC = cc
	OBJ = main.c utils.c mandelbrot.c julia.c
NAME = frac

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lminilibx-linux -lmlx -o $(NAME) -lX11 -lm -lz -lXext

clean:
	rm -rf $(NAME)
