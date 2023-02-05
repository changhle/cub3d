# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: changhle <changhle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 09:21:55 by changhle          #+#    #+#              #
#    Updated: 2023/02/05 16:52:09 by changhle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				:=	cc
CFLAGS			:=	-Wall -Werror -Wextra
RM				:=	rm -f

NAME			:=	cub3D

PARSE_DIR		:=	parse
PARSE_SRCS		:=	parse.c \
					init_texture.c parse_texture_data.c get_texture.c \
					init_map_content.c copy_map.c check_map.c t_buffer.c \
					init_coord_value.c check_map_helper.c init_sprite_utils.c
PARSE_SRCS		:=	$(addprefix $(PARSE_DIR)/, $(PARSE_SRCS))

RENDER_DIR		:=	render
RENDER_SRCS		:=	init_mlx.c draw_screen.c draw_minimap.c \
					raycast.c sprite_cast.c sprite_cast_bubble.c
RENDER_SRCS		:=	$(addprefix $(RENDER_DIR)/, $(RENDER_SRCS))

EVENT_DIR		:=	event
EVENT_SRCS		:=	event.c move_engine.c move_mouse.c move_player.c \
					move_door.c move_sprite.c rotate_sight.c
EVENT_SRCS		:=	$(addprefix $(EVENT_DIR)/, $(EVENT_SRCS))

UTIL_DIR		:=	util
UTIL_SRCS		:=	exit.c
UTIL_SRCS		:=	$(addprefix $(UTIL_DIR)/, $(UTIL_SRCS))

SRCS_DIR		:=	srcs
SRCS			:=	main.c \
					$(PARSE_SRCS) \
					$(RENDER_SRCS) \
					$(EVENT_SRCS) \
					$(UTIL_SRCS)
SRCS			:=	$(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS			:=	$(SRCS:.c=.o)

INCS_DIR		:=	includes

LIBFT_DIR		:=	libft
LIBFT			:=	$(LIBFT_DIR)/libft.a

MINILIBX_DIR	:=	minilibx
MINILIBX		:=	libmlx.dylib

NORMINETTE		:=	norminette

.PHONY			:	all
all				:	$(NAME)

$(NAME)			:	$(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

%.o				:	%.c
	$(CC) $(CFLAGS) -I$(INCS_DIR) -I$(LIBFT_DIR) -I$(MINILIBX_DIR) -c $< -o $@

$(LIBFT)		:
	$(MAKE) -C $(LIBFT_DIR) all

$(MINILIBX)		:
	$(MAKE) -C $(MINILIBX_DIR)
	mv $(MINILIBX_DIR)/$(MINILIBX) .

.PHONY			:	clean
clean			:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

.PHONY			:	fclean
fclean			:	clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MINILIBX_DIR) clean
	$(RM) $(MINILIBX)

.PHONY			:	re
re				:
	make fclean
	make all

.PHONY			:	norm
norm 			:
	$(NORMINETTE) $(SRCS)
