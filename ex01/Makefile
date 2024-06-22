# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 10:37:38 by mel-aini          #+#    #+#              #
#    Updated: 2023/11/08 10:37:38 by mel-aini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01

HEADERS = ClapTrap.hpp ScavTrap.hpp

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $@

%.o : %.cpp $(HEADERS)
	c++ $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re