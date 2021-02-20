# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/20 18:17:44 by vvaucoul          #+#    #+#              #
#    Updated: 2021/02/20 19:14:05 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     := clean_dir
SRCS     := core/cleanDir.cpp \
			core/main.cpp

OBJS     := $(SRCS:.cpp=.o)
CXX      := clang++
CXXFLAGS := -std=c++98 -Wall -Werror -Wextra -I. -g3

all: $(NAME)

$(NAME): $(OBJS) $(HDRS)
	@$(CXX) $(OBJS) -o $@

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean format re
