# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amecani <amecani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 10:54:25 by amecani           #+#    #+#              #
#    Updated: 2024/03/25 19:14:26 by amecani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# cc client.c -I ./print_F 

SERVER_NAME = server
CLIENT_NAME = client

CFLAGS = -Wall -Werror -Wextra

LIBFT_PATH = ./print
LIBFT = $(LIBFT_PATH)/libftprintf.a

CLIENT_SOURCES = client.c 
SERVER_SOURCES = server.c

SERVER_OBJECTS = $(SERVER_SOURCES:.c=.o)
CLIENT_OBJECTS = $(CLIENT_SOURCES:.c=.o)

all: $(SERVER_NAME) $(CLIENT_NAME)

$(CLIENT_NAME): $(LIBFT) $(CLIENT_OBJECTS)
	@cc $(CFLAGS) $(LIBFT) -o $(CLIENT_NAME) $(CLIENT_OBJECTS)

$(SERVER_NAME): $(LIBFT) $(SERVER_OBJECTS)
	@cc $(CFLAGS) $(LIBFT) -o $(SERVER_NAME) $(SERVER_OBJECTS)

$(LIBFT):
	@make -C $(LIBFT_PATH)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C $(LIBFT_PATH)
	rm -f $(SERVER_OBJECTS) $(CLIENT_OBJECTS)

fclean: clean
	rm -rf $(SERVER_NAME) $(CLIENT_NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

bonus: all
# cc  -I ./print -L ./print_F -lftprintf server.c && ./a.out