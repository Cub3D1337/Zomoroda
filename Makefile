NAME        = cub3D
BONUS_NAME	= cub3D_bonus
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -O3
LDFLAGS     = -L./Libft -lft

M_BUILD_DIR = mandatory/build
B_BUILD_DIR = bonus/build

LIBFT_DIR	= ./Libft
LIBFT       = $(LIBFT_DIR)/libft.a

MAND_DIR	= ./mandatory/src
MAND_INC	= ./mandatory/includes
MAND_INIT_DIR    = $(MAND_DIR)/init
MAND_EVENTS_DIR  = $(MAND_DIR)/events
MAND_RAYCASTING_DIR = $(MAND_DIR)/raycasting
MAND_TEX_DIR     = $(MAND_DIR)/textures
MAND_RENDER_DIR  = $(MAND_DIR)/render
MAND_UTILS_DIR   = $(MAND_DIR)/utils
M_INCLUDES    = -I$(MAND_INC) -I$(LIBFT_DIR)/includes

BONUS_DIR	= ./bonus/src
BONUS_INC	= ./bonus/includes
BONUS_INIT_DIR    = $(BONUS_DIR)/init
BONUS_EVENTS_DIR  = $(BONUS_DIR)/events
BONUS_RAYCASTING_DIR = $(BONUS_DIR)/raycasting
BONUS_TEX_DIR     = $(BONUS_DIR)/textures
BONUS_RENDER_DIR  = $(BONUS_DIR)/render
BONUS_UTILS_DIR   = $(BONUS_DIR)/utils
B_INCLUDES    = -I$(BONUS_INC) -I$(LIBFT_DIR)/includes

# ---------------- Mandatory ----------------
MAND_INIT        = 	$(MAND_INIT_DIR)/init.c $(MAND_INIT_DIR)/buffers.c
MAND_EVENTS      = 	$(MAND_EVENTS_DIR)/events.c $(MAND_EVENTS_DIR)/keys.c \
             		$(MAND_EVENTS_DIR)/move.c $(MAND_EVENTS_DIR)/utils.c
MAND_RAYCASTING  = 	$(MAND_RAYCASTING_DIR)/raycaster.c $(MAND_RAYCASTING_DIR)/dda.c
MAND_TEX         = 	$(MAND_TEX_DIR)/init.c $(MAND_TEX_DIR)/textures.c
MAND_RENDER      = 	$(MAND_RENDER_DIR)/render.c
MAND_UTILS       = 	$(MAND_UTILS_DIR)/cleanup.c $(MAND_UTILS_DIR)/utils.c $(MAND_UTILS_DIR)/gets.c

MAND_SRCS        =	$(MAND_DIR)/main.c $(MAND_INIT) $(MAND_EVENTS) $(MAND_RAYCASTING) \
            		$(MAND_TEX) $(MAND_RENDER) $(MAND_UTILS) \
            		$(MAND_DIR)/parsing/parsing.c \
            		$(MAND_DIR)/parsing/parsing2.c $(MAND_DIR)/parsing/parsing3.c \
            		$(MAND_DIR)/parsing/parsing4.c $(MAND_DIR)/parsing/parsing_command.c \
            		$(MAND_DIR)/parsing/parsing_command2.c $(MAND_DIR)/parsing/parsing_command3.c \
            		$(MAND_DIR)/parsing/parsing_command4.c $(MAND_DIR)/parsing/parsing_command5.c \
            		$(MAND_DIR)/parsing/parsing_command6.c $(MAND_DIR)/parsing/parsing_command7.c

# ---------------- Bonus ----------------
BONUS_INIT        = $(BONUS_INIT_DIR)/init_bonus.c $(BONUS_INIT_DIR)/buffers_bonus.c
BONUS_EVENTS      = $(BONUS_EVENTS_DIR)/events_bonus.c $(BONUS_EVENTS_DIR)/keys_bonus.c \
              		$(BONUS_EVENTS_DIR)/move_bonus.c $(BONUS_EVENTS_DIR)/utils_bonus.c $(BONUS_EVENTS_DIR)/mouse_bonus.c
BONUS_RAYCASTING  = $(BONUS_RAYCASTING_DIR)/raycaster_bonus.c $(BONUS_RAYCASTING_DIR)/dda_bonus.c
BONUS_TEX         = $(BONUS_TEX_DIR)/init_bonus.c $(BONUS_TEX_DIR)/textures_bonus.c $(BONUS_TEX_DIR)/intro_bonus.c
BONUS_RENDER      = $(BONUS_RENDER_DIR)/render_bonus.c $(BONUS_RENDER_DIR)/minimap_bonus.c $(BONUS_RENDER_DIR)/animation_bonus.c
BONUS_UTILS       = $(BONUS_UTILS_DIR)/cleanup_bonus.c $(BONUS_UTILS_DIR)/utils_bonus.c $(BONUS_UTILS_DIR)/music_bonus.c $(BONUS_UTILS_DIR)/gets_bonus.c
BONUS_SRCS        = $(BONUS_DIR)/main_bonus.c $(BONUS_INIT) $(BONUS_EVENTS) $(BONUS_RAYCASTING) \
       				$(BONUS_TEX) $(BONUS_RENDER) $(BONUS_UTILS) \
       				$(BONUS_DIR)/parsing/parsing_bonus.c \
       				$(BONUS_DIR)/parsing/parsing2_bonus.c $(BONUS_DIR)/parsing/parsing3_bonus.c \
       				$(BONUS_DIR)/parsing/parsing4_bonus.c $(BONUS_DIR)/parsing/parsing_command_bonus.c \
       				$(BONUS_DIR)/parsing/parsing_command2_bonus.c $(BONUS_DIR)/parsing/parsing_command3_bonus.c \
       				$(BONUS_DIR)/parsing/parsing_command4_bonus.c $(BONUS_DIR)/parsing/parsing_command5_bonus.c \
       				$(BONUS_DIR)/parsing/parsing_command6_bonus.c $(BONUS_DIR)/parsing/parsing_command7_bonus.c


MAND_OBJS = $(MAND_SRCS:$(MAND_DIR)/%.c=$(M_BUILD_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:$(BONUS_DIR)/%.c=$(B_BUILD_DIR)/%.o)

# ---------------- Rules ----------------
all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(BONUS_NAME)

$(NAME): $(MAND_OBJS)
	$(CC) $(CFLAGS) $(MAND_OBJS) $(LIBFT) $(M_INCLUDES) \
		-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux \
		-lXext -lX11 -lm -lz -o $(NAME) $(LDFLAGS)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(B_INCLUDES) \
		-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux \
		-lXext -lX11 -lm -lz -o $(BONUS_NAME) $(LDFLAGS)

mandatory/build/%.o: $(MAND_DIR)/%.c $(MAND_INC)/* $(MAND_INC)/typedef/*
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(M_INCLUDES) -c $< -o $@

bonus/build/%.o: $(BONUS_DIR)/%.c $(BONUS_INC)/* $(BONUS_INC)/typedef/*
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(B_INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(M_BUILD_DIR)
	rm -rf $(B_BUILD_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)
	rm -rf $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus