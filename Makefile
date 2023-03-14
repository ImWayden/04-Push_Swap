# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wayden <wayden@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 09:08:09 by wayden            #+#    #+#              #
#    Updated: 2023/03/14 10:18:08 by wayden           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSHSWAP = push_swap
CHECKER = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

UTILFILES =  util util2 instruction1 instruction2 shortsort basicsort
PSWFILES = main 
CHECKERFILES = checker
LIBFTFILES = libft

OBJS_DIR = ./
UTIL_DIR = ./src/util/
PSW_DIR = ./src/push_swap/
CHECKER_DIR = ./src/checker/
HEADER_DIR = ./header/
LIBFT_DIR = ./Libft/

LIBFT_SRC = $(addprefix $(LIBFT_DIR), $(addsuffix .a, $(LIBFTFILES)))
PSW_SRC = $(addprefix $(PSW_DIR), $(addsuffix .c, $(PSWFILES)))
UTIL_SRC = $(addprefix $(UTIL_DIR), $(addsuffix .c, $(UTILFILES)))
CHECKER_SRC = $(addprefix $(CHECKER_DIR), $(addsuffix .c, $(CHECKERFILES)))

all: $(PUSHSWAP) $(CHECKER)


$(PUSHSWAP) : $(PSW_SRC) $(UTIL_SRC) $(LIBFT_SRC)
	${CC} $(CFLAGS) $^ -o $@

$(CHECKER) : $(CHECKER_SRC) $(UTIL_SRC) $(LIBFT_SRC)
	${CC} $(CFLAGS) $^ -o $@
	
$(LIBFT_SRC):
	$(MAKE) -C $(LIBFT_DIR)
	
clean:
	rm -f $(PUSHSWAP) $(CHECKER)
	$(MAKE) -C $(LIBFT_DIR) clean
fclean: clean
	rm -f $(PUSHSWAP) $(CHECKER)
	$(MAKE) -C $(LIBFT_DIR) fclean
re : fclean all

.PHONY: