# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/18 12:33:16 by tkeil             #+#    #+#              #
#    Updated: 2025/03/10 14:48:25 by tkeil            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++  
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME =  ex01
OBJSDIR = objs/

SRCS = main.cpp Zombie.cpp zombieHorde.cpp
OBJS = $(SRCS:%.cpp=$(OBJSDIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJSDIR)%.o: %.cpp
	@mkdir -p $(OBJSDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
