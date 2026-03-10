# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/24 12:34:46 by hsamira           #+#    #+#              #
#    Updated: 2026/02/24 12:34:47 by hsamira          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Form

CXX = c++

CXXFLAG = -Wall -Werror -Wextra -std=c++98 -MMD -MP

SRC =  Bureaucrat.cpp main.cpp Form.cpp

OBJ = $(SRC:.cpp=.o)

DEPS = $(SRC:.cpp=.d)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAG) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(CXX) $(CXXFLAG) -c $< -o $@

clean: 
	rm -f $(OBJ)
	rm -f $(DEPS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY : re all clean fclean
-include $(DEPS)