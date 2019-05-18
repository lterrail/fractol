# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/16 13:56:16 by lterrail          #+#    #+#              #
#    Updated: 2019/05/18 16:35:36 by lterrail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

SRC	=	main.c						\
		clear_img.c					\
		new_image.c					\
		draw_pixel.c				\
		key.c						\
		draw.c						\
		color.c						\
		julia.c						\
		mandelbrot.c				\
		burningship.c				\
		mouse.c						\

OBJ		= $(addprefix ./obj/,$(SRC:.c=.o))

CC		= gcc
X11DIR = -I./Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/

CFLAGS	= -Wall -Wextra -Werror

LIBFTA	= ./libft/libft.a
LIBINCL = -I./libft/includes
LIBLINK	= -L./libft -lft -l pthread

MLXA = ./miniLibX/mlx.a
MLXINCL = -I./miniLibX
MLXLINK = -L./miniLibX -l mlx -framework OpenGL -framework AppKit

all: obj $(LIBFTA) $(MLXA) $(NAME)

obj:
	mkdir -p ./obj/

./obj/%.o:./srcs/%.c
	$(CC) $(CFLAGS) $(LIBINCL) $(MLXINCL) $(X11DIR) -Iincludes -o $@ -c $<

$(LIBFTA):
	make -C ./libft

$(MLXA):
	make -C ./miniLibX

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBLINK) $(MLXLINK)

clean:
	rm -rf ./obj/
	make -C ./libft clean
	make -C ./miniLibX clean

fclean: clean
	rm -rf $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
