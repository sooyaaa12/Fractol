NAME = fractol
SRCS = $(shell find srcs -name '*.c')
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS =  -Lmlx -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

all : $(NAME)

%.o : %.c Makefile fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(MAKE) -C mlx
	$(MLX)
	$(CC) $(MLXFLAGS) -o $(NAME) mlx/libmlx.a $(OBJS)

MLX:
	$(MAKE) -C mlx

clean :
	$(RM) $(OBJS)
	$(MAKE) -C mlx clean

fclean : clean
	$(RM) $(NAME)
	$(RM) mlx/libmlx.a

re : fclean all

.PHONY : all clean fclean re
