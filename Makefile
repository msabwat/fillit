# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 12:02:10 by schaaban          #+#    #+#              #
#    Updated: 2018/04/26 16:37:06 by msabwat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fillit

CC				=	clang

FLAGS			=	-Wall -Wextra -Werror

LIB_P			=	./libft

SRC_PATH		=	src

OBJ_PATH		=	bin

CPPFLAGS		=	-Iinc

LDFLAGS			=	-Llibft

LDLIBS			=	-lft

SRC_NAME		=	get_one_line.c			\
					main.c					\
					read_file.c				\
					checker.c				\
					tetri.c					\
					tools1.c				\
					tools2.c				\
					solve.c					\
					ft_atoi_base.c			\
					map.c					\
					ft_sqrt.c				\
					ft_free.c				\
					ft_itoa_base.c

OBJ_NAME		=	$(SRC_NAME:.c=.o)

SRC				=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ				=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIB_P) 
	@echo "FILLIT - Exe creation"
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p bin
	@$(CC) $(FLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@echo "FILLIT - Cleaning objects"
	@rm -Rf $(OBJ_PATH)
	@$(MAKE) -C $(LIB_P) clean

fclean: clean
	@echo "FILLIT - Full clean (objects + exe)"
	@rm -Rf $(NAME)
	@$(MAKE) -C $(LIB_P) fclean

re: fclean all
