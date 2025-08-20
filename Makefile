NAME = 			cub3D
CC =			 cc
FLAGS = 		-Wall -Wextra -Werror -g
LDFLAGS = 		-L./Libft -lft

INC_DIR =		./includes
LIBFT_DIR =		./Libft
SRC_DIR = 		./src

INCLUDES =		-I${INC_DIR} -I./Libft/includes
LIBFT =			$(LIBFT_DIR)/libft.a

OBJS =			$(SRCS:.c=.o)

SRCS =			$(SRC_DIR)/main.c $(SRC_DIR)/parsing.c $(SRC_DIR)/init.c $(SRC_DIR)/draw.c $(SRC_DIR)/events.c $(SRC_DIR)/utils.c $(SRC_DIR)/cleanup.c \
				$(SRC_DIR)/map.c $(SRC_DIR)/move.c $(SRC_DIR)/raycasting.c $(SRC_DIR)/dda.c $(SRC_DIR)/textures.c

all:			$(LIBFT) $(NAME)

$(NAME):		$(OBJS)
					$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INCLUDES) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LDFLAGS)

%.o: %.c		${INC_DIR}/cub3d.h $(INC_DIR)/parsing.h ${INC_DIR}/mlx.h ${INC_DIR}/includes.h
					$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

$(LIBFT):
				make -C $(LIBFT_DIR)

clean:
				make clean -C $(LIBFT_DIR)
				rm -f $(OBJS)

fclean:			clean
					make fclean -C $(LIBFT_DIR)
					rm -f $(NAME)

re:				fclean all

vg:
	valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY:			all clean fclean re
