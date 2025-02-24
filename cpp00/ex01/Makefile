# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/04 12:15:45 by tkeil             #+#    #+#              #
#    Updated: 2025/02/05 13:10:42 by tkeil            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXX = c++  
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = phonebook

SRCS = main.cpp contact.cpp phonebook.cpp
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
