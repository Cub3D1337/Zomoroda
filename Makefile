NAME        = cub3D
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -O3
LDFLAGS     = -L./Libft -lft

LIBFT_DIR   = ./Libft
MAN_DIR     = ./mandatory/src
MAND_INC     = ./mandatory/includes
BONUS_INC     = ./bonus/includes

INIT_DIR    = $(MAN_DIR)/init
EVENTS_DIR  = $(MAN_DIR)/events
RAYCASTING_DIR = $(MAN_DIR)/raycasting
TEX_DIR     = $(MAN_DIR)/textures
RENDER_DIR  = $(MAN_DIR)/render
UTILS_DIR   = $(MAN_DIR)/utils

M_INCLUDES    = -I$(MAND_INC) -I$(LIBFT_DIR)/includes
B_INCLUDES    = -I$(MAND_INC) -I$(LIBFT_DIR)/includes
LIBFT       = $(LIBFT_DIR)/libft.a

INIT        = $(INIT_DIR)/init.c $(INIT_DIR)/buffers.c
EVENTS      = $(EVENTS_DIR)/events.c $(EVENTS_DIR)/keys.c \
              $(EVENTS_DIR)/move.c $(EVENTS_DIR)/utils.c
RAYCASTING  = $(RAYCASTING_DIR)/raycaster.c $(RAYCASTING_DIR)/dda.c
TEX         = $(TEX_DIR)/init.c $(TEX_DIR)/textures.c $(TEX_DIR)/intro.c
RENDER      = $(RENDER_DIR)/render.c $(RENDER_DIR)/minimap.c
UTILS       = $(UTILS_DIR)/cleanup.c $(UTILS_DIR)/utils.c \
              $(UTILS_DIR)/music.c $(UTILS_DIR)/gets.c

SRCS        = $(MAN_DIR)/main.c $(INIT) $(EVENTS) $(RAYCASTING) \
              $(TEX) $(RENDER) $(UTILS) \
              $(MAN_DIR)/parsing/parsing.c \
              $(MAN_DIR)/parsing/parsing2.c $(MAN_DIR)/parsing/parsing3.c \
              $(MAN_DIR)/parsing/parsing4.c $(MAN_DIR)/parsing/parsing_command.c \
              $(MAN_DIR)/parsing/parsing_command2.c $(MAN_DIR)/parsing/parsing_command3.c \
              $(MAN_DIR)/parsing/parsing_command4.c $(MAN_DIR)/parsing/parsing_command5.c \
              $(MAN_DIR)/parsing/parsing_command6.c $(MAN_DIR)/parsing/parsing_command7.c

OBJS        = $(SRCS:.c=.o)

# ---------------- Rules ----------------
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INCLUDES) \
		-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux \
		-lXext -lX11 -lm -lz -o $(NAME) $(LDFLAGS)

%.o: %.c $(INC_DIR)/* $(INC_DIR)/typedef/*
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
