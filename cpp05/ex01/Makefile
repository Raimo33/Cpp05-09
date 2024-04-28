# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 15:33:59 by craimond          #+#    #+#              #
#    Updated: 2024/04/26 16:11:48 by craimond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

SRCS = main.cpp Bureaucrat.cpp Form.cpp
OBJS = $(SRCS:.cpp=.o)
HDRS = Bureaucrat.hpp Form.hpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJS) $(HDRS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) is ready$(NC)"

%.o: %.cpp
	@echo "compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "cleaning $(NAME)"
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@echo "$(RED)cleaned $(NAME)$(NC)"

re: clean all

.PHONY: all clean re
