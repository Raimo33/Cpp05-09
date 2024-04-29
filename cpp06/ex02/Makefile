# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 15:33:59 by craimond          #+#    #+#              #
#    Updated: 2024/04/29 14:37:24 by craimond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = identifier

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
HDRS = Base.hpp A.hpp B.hpp C.hpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJS) $(HDRS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)compiled $(NAME)$(NC)"

%.o: %.cpp
	@echo "compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)removed $(OBJS)$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)removed $(NAME)$(NC)"

re: fclean all

.PHONY: all clean re

.SILENT: all $(NAME) $(OBJS) clean fclean re

.IGNORE: clean fclean
