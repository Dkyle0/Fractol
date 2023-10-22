# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkyle <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 18:34:48 by dkyle             #+#    #+#              #
#    Updated: 2019/02/15 18:34:49 by dkyle            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

SRC		= main.c  mini_f.c general.c mouse.c help_and_key.c help2.c build_cl.c

OBJ		= $(SRC:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

MLX		= ./miniLibX/
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./miniLibX
MLX_LNK	= -L ./miniLibX -l mlx -framework OpenGL -framework AppKit -framework OpenCL

FT		= ./src/libft
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./src/libft
FT_LNK	= -L ./src/libft -l ft

SRCDIR	= ./src/
INCDIR	= ./includes/

all: $(FT_LIB) $(MLX_LIB) $(NAME)

%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(MLX_LIB):
	make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	rm -rf *.o
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf *.o
	make -C $(FT) fclean

re: fclean all