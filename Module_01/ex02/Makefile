# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 17:38:23 by abollen           #+#    #+#              #
#    Updated: 2023/01/16 09:56:22 by abollen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#***** VARIABLES *****#

PROJECT = hi_this_is_brain
NAME = ./hi_this_is_brain

FILES = main.cpp
OBJ = ${FILES:.cpp=.o}

CC = c++
CFLAGS = -Wall -Wextra -Werror -Iincludes -std=c++98

#***** RULES *****#

all : ${NAME}

%.o : %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[95m[${PROJECT}]\033[92m[BUILD]\033[97m $@."

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)
	@echo "\033[36m[${PROJECT}]\033[92m[BUILD] \033[0m${NAME}"
	
clean :
	@rm -rf ${OBJ}
	@echo "\033[36m[${PROJECT}]\033[93m[CLEAN] \033[0m${OBJ}"

fclean : clean
	@rm -rf ${NAME}
	@echo "\033[36m[${PROJECT}]\033[93m[CLEAN] \033[0m${NAME}"

re: fclean all

.PHONY : all clean fclean re