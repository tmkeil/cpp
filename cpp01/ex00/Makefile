# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 12:45:30 by tkeil             #+#    #+#              #
#    Updated: 2025/03/10 13:34:29 by tkeil            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++  
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME =  ex00

SRCS = main.cpp Zombie.cpp randomChump.cpp newZombie.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test:
	echo $(OBJS)

.PHONY: all clean fclean re
