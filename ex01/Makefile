# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 08:59:19 by mel-aini          #+#    #+#              #
#    Updated: 2023/11/07 08:59:40 by mel-aini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook

HEADER = PhoneBook.hpp Contact.hpp utils.hpp 

SRC = main.cpp PhoneBook.cpp Contact.cpp utils.cpp

OBJ = main.o PhoneBook.o Contact.o utils.o

FLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $@

%.o : %.cpp $(HEADER)
	c++ $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re