NAME=so_long
CC=clang
CFLAGS=-Wall -Werror -Wextra -g -g3
LIBS= -L ./srcs/minilibx-linux/ -lmlx -L ./srcs/libft/ -lft -lXext -lX11
SRCS=./srcs/file_c_h/so_long.c \
     ./srcs/file_c_h/open_file.c \
     ./srcs/file_c_h/stock_map.c \
     ./srcs/file_c_h/utils.c \
     ./srcs/file_c_h/check_map.c \
     ./srcs/file_c_h/flood.c \
     ./srcs/file_c_h/utils_mlx.c \
     ./srcs/file_c_h/init_textures.c \
     ./srcs/file_c_h/render.c \
     ./srcs/file_c_h/check_collect_and_floor.c

OBJS=$(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: mlx libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS) -lm

mlx:
	make -C ./srcs/minilibx-linux/

libft:
	make -C ./srcs/libft/

clean :
	rm -rf $(OBJS)
	make clean -C ./srcs/minilibx-linux/
	make clean -C ./srcs/libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./srcs/libft/

re: fclean all

.PHONY: all re clean fclean
