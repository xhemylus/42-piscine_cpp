# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 17:38:23 by abollen           #+#    #+#              #
#    Updated: 2022/05/17 14:51:12 by abollen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#***** VARIABLES *****#

PROJECT = Zombie Horde
NAME = ./zombiehorde

FILES = Zombie.cpp zombieHorde.cpp main.cpp
OBJ = ${addprefix ${OBJ_DIR}/,${FILES:.cpp=.o}}

SRC_DIR = src
OBJ_DIR = obj

HEADER = includes/

CC = c++
CFLAGS = -Wall -Wextra -Werror -Iincludes -std=c++98

#***** RULES *****#

all : ${OBJ_DIR} ${NAME}

${OBJ_DIR}/%.o : ${SRC_DIR}/%.cpp ${HEADER}
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
	@echo "\033[36m[${PROJECT}]\033[93m[CLEAN] \033[0m${OBJ_DIR} folder"

fclean : clean
	@rm -rf ${NAME}
	@echo "\033[36m[${PROJECT}]\033[93m[CLEAN] \033[0m${NAME}"

re: fclean all

.PHONY : all clean fclean re