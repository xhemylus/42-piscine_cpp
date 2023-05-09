# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 17:38:23 by abollen           #+#    #+#              #
#    Updated: 2023/01/20 10:58:15 by abollen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#***** VARIABLES *****#

PROJECT = Reverse Polish Notation
NAME = ./rpn

FILES = main.cpp rpn.cpp
OBJ = ${addprefix ${OBJ_DIR}/,${FILES:.cpp=.o}}

SRC_DIR = src
OBJ_DIR = obj

HEADER = includes/rpn.hpp

CC = c++
CFLAGS = -Wall -Werror -Wextra -Iincludes -std=c++98

#***** RULES *****#

all : ${OBJ_DIR} ${NAME}

${OBJ_DIR}/%.o : ${SRC_DIR}/%.cpp ${HEADER} Makefile
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[95m[${PROJECT}]\033[92m[BUILD]\033[97m $@."

$(NAME): ${OBJ}
	@${CC} ${OBJ} -o ${NAME}
	@echo "\033[36m[${PROJECT}]\033[92m[BUILD] \033[0m${NAME}"

${OBJ_DIR}:
	@mkdir obj
	@echo "\033[36m[${PROJECT}]\033[92m[BUILD] \033[0m${OBJ_DIR} folder"

clean :
	@rm -rf ${OBJ_DIR}
	@echo "\033[36m[${PROJECT}]\033[93m[CLEAN] \033[0m${OBJ}"

fclean : clean
	@rm -rf ${NAME}
	@echo "\033[36m[${PROJECT}]\033[93m[CLEAN] \033[0m${NAME}"

re: fclean all

.PHONY : all clean fclean re