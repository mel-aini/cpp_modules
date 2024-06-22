# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 12:53:30 by mel-aini          #+#    #+#              #
#    Updated: 2023/11/25 10:03:14 by mel-aini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex03

HEADERS = AMateria.hpp Character.hpp Cure.hpp ICharacter.hpp Ice.hpp IMateriaSource.hpp MateriaSource.hpp

SRC = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	@c++ $(FLAGS) $(OBJ) -o $@

%.o : %.cpp $(HEADERS)
	@c++ $(FLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

run : all clean
	@./$(NAME)

.PHONY : clean fclean re run