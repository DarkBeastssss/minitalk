# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amecani <amecani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 10:54:25 by amecani           #+#    #+#              #
#    Updated: 2024/03/25 12:32:39 by amecani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -rf
CC = cc
CCFLAGS = -Wall -Wextra -Werror -Ilibft
ADD = -fsanitize=address -g
OBJ+ = $(C_FILES:.c=.o) $(BONUS_FILES:.c=.o)
# LIBFT_D = libft/
DEBUGGER = debugger/
NAME = libftprintf.a
H_FILE = ft_printf.h
C_FILES = ft_printf.c mc_dispenser_uppercase.c fck_norm.c ft_atoi.c
.PHONY: clean fclean re all
all: $(NAME)
# bonus: all
$(NAME) :  $(OBJ+)
	@$(LIB) $(NAME) $(OBJ+)

%.o : %.c 
	@$(CC) $(CCFLAGS) -c -o $@ $<
clean:
	@$(RM) $(OBJ+)
fclean: clean
	@$(RM) $(NAME)
re: fclean all
%: c  %.c
	@$(CC) $(ADD) $(CCFLAGS) $(H_FILE) $(C_FILES) 
	@mv a.out.dSYM $(DEBUGGER)
	@mv a.out $(DEBUGGER)
	@mv *.gch $(DEBUGGER)
	@make fclean
# @$(RM) $(LIBFT_D)*.gch
c: fclean
	@$(RM) $(DEBUGGER)* 
# @$(RM) $(LIBFT_D)*.gch 
	@$(RM) *.out *.dSYM *.gch