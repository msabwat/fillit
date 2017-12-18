# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 12:02:10 by schaaban          #+#    #+#              #
#    Updated: 2017/12/16 17:37:32 by msabwat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit

LIB_P		=	./libft

FLAGS		=	-Wall -Wextra -Werror

SRCS		=	get_one_line.c			\
				main.c								\
				read_file.c						\
				checker.c							\
				tetri.c								\
				tools1.c							\
				tools2.c							\
				solve.c								\
				ft_atoi_base.c				\
				map.c									\
				ft_sqrt.c							\
				ft_free.c							\
				ft_itoa_base.c

OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "FILLIT - Exe creation"
	@gcc $(FLAGS) -L$(LIB_P) -lft $(OBJS) -o $(NAME)

$(OBJS): $(SRCS)
	@$(MAKE) -C $(LIB_P)
	@gcc $(FLAGS) -c $(SRCS)

clean:
	@echo "FILLIT - Cleaning objects"
	@rm -Rf $(OBJS)
	@$(MAKE) -C $(LIB_P) clean

fclean: clean
	@echo "FILLIT - Full clean (objects + exe)"
	@rm -Rf $(NAME)
	@$(MAKE) -C $(LIB_P) fclean

re: fclean all
