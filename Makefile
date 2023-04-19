# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 13:30:50 by rmakinen          #+#    #+#              #
#    Updated: 2023/04/18 08:22:18 by rmakinen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
FILES = server
FILES2 = client
SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES))
SRC2 = $(addsuffix .c, $(FILES2))
OBJ2 = $(addsuffix .o, $(FILES2))
FLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(SERVER): $(SRC)
	@cd libft && $(MAKE)
	@cc -o $(SERVER) $(FLAGS) $(SRC) -L. ./libft/libft.a

$(CLIENT): $(SRC2)
	@cd libft && $(MAKE)
	@cc -o $(CLIENT) $(FLAGS) $(SRC2) -L. ./libft/libft.a

clean:
	@cd libft && make clean
	@/bin/rm -f $(OBJ) $(OBJ2)

fclean: clean
	@cd libft && make fclean
	@/bin/rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
