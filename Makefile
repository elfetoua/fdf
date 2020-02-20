# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 20:07:06 by elfetoua          #+#    #+#              #
#    Updated: 2020/02/20 22:40:41 by elfetoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf

SRC_PATH= src
SRC_NAME = main.c read_file.c get_next_line.c draw.c basic.c
SRC= $(addprefix $(SRC_PATH)/, $(SRC_NAME))

INC_NAME= fdf.h get_next_line.h
INC_PATH= includes
INC= $(addprefix $(INC_PATH)/, $(INC_NAME)) # adding path to inc name

OBJ_PATH= obj
OBJ_NAME= $(SRC_NAME:.c=.o)
OBJ= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))


LIB= libft/libft.a

CW= gcc
MLX = -lmlx -framework OpenGL -framework AppKit
CFLAGS= -Wall -Wextra -Werror

# **************************************************************************** #


all: libf $(NAME)

libf:
	@make -sC libft 

$(NAME): $(LIB) $(OBJ)
	$(CW) $(MLX) $(LIB) $(OBJ) -o $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CW) $(CFLAGS) -I $(INC_PATH) -o $@ -c $< 

$(LIB): libf 



clean:
	@rm -fr $(OBJ)
	@rm -fr $(OBJ_PATH)
	@make -C libft clean 

fclean:
	@rm -fr $(OBJ)
	@rm -fr $(OBJ_PATH)
	@rm -fr $(NAME)
	@make -C libft fclean

re: fclean all 