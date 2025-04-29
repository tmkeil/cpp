# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 12:25:53 by tkeil             #+#    #+#              #
#    Updated: 2025/04/29 14:43:05 by tkeil            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++  
CXXFLAGS = -Wall -Wextra -Werror -std=c++17
NAME =  ex02
OBJSDIR = objs/

SRCS = main.cpp Array.cpp Array.tpp
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
