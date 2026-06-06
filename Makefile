# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daherman <daherman@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/01 11:07:29 by daherman          #+#    #+#              #
#    Updated: 2026/06/06 15:00:05 by hfandino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

# --- PATH ---
LIBFT_DIR = libs/libft

# --- INCLUDES ---
INCLUDES = -I include -I $(LIBFT_DIR)

# --- LINK libft ---
LIBFT = $(LIBFT_DIR)/libft.a

# --- SOURCES ---
SRC_DIR = src

SRC = \
      $(SRC_DIR)/main.c \
      $(SRC_DIR)/parsing/arg_checkers.c \
      $(SRC_DIR)/stack/node_new.c \
      $(SRC_DIR)/stack/node_addback.c \
      $(SRC_DIR)/stack/node_addfront.c \
      $(SRC_DIR)/stack/node_last.c \
      $(SRC_DIR)/stack/node_clear.c \
      $(SRC_DIR)/operations/swap.c \
      $(SRC_DIR)/operations/push.c

OBJ = $(SRC:.c=.o)

# --- RULES ---

all: $(NAME)

# ---compile libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# ---final link
$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME)

# compile .c -> .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
