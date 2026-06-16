# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daherman <daherman@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/01 11:07:29 by daherman          #+#    #+#              #
#    Updated: 2026/06/12 18:33:57 by hfandino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# --- FOR TESTS ---
TEST_INDEX = test_index
TEST_NODE = test_node

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
      $(SRC_DIR)/parsing/parse_utils.c \
      $(SRC_DIR)/parsing/build_stack.c \
      $(SRC_DIR)/parsing/check_flag.c \
      $(SRC_DIR)/stack/node_new.c \
      $(SRC_DIR)/stack/node_addback.c \
      $(SRC_DIR)/stack/node_addfront.c \
      $(SRC_DIR)/stack/node_last.c \
      $(SRC_DIR)/stack/node_clear.c \
      $(SRC_DIR)/analysis/compute_disorder.c \
      $(SRC_DIR)/analysis/index_utils.c \
      $(SRC_DIR)/analysis/index.c \
      $(SRC_DIR)/analysis/check_order.c \
      $(SRC_DIR)/operations/swap.c \
      $(SRC_DIR)/operations/push.c \
      $(SRC_DIR)/operations/rotate.c \
      $(SRC_DIR)/operations/reverse_rotate.c \
      $(SRC_DIR)/sort/sort_2.c \
      $(SRC_DIR)/sort/sort_3.c \
      $(SRC_DIR)/sort/sort_5.c \
      $(SRC_DIR)/dispatch/dispatch.c \
      $(SRC_DIR)/strategies/simple_sort.c \
      $(SRC_DIR)/strategies/medium_sort.c \
      $(SRC_DIR)/strategies/adaptative_sort.c \
      $(SRC_DIR)/strategies/complex_sort.c \
      $(SRC_DIR)/bench/check_bench_strat.c \
      $(SRC_DIR)/bench/print_bench.c

OBJ = $(SRC:.c=.o)

STACK_SRC = \
	$(SRC_DIR)/stack/node_new.c \
	$(SRC_DIR)/stack/node_addback.c \
	$(SRC_DIR)/stack/node_addfront.c \
	$(SRC_DIR)/stack/node_last.c \
	$(SRC_DIR)/stack/node_clear.c

INDEX_SRC = \
	$(SRC_DIR)/analysis/index.c \
	$(SRC_DIR)/analysis/index_utils.c

PARSING_SRC = \
	src/parsing/arg_checkers.c \
	src/parsing/build_stack.c

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

test_index:
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) \
	tests/test_index.c \
	$(STACK_SRC) \
	$(INDEX_SRC) \
	$(PARSING_SRC) \
	$(LIBFT) \
	-o $(TEST_INDEX)
	./$(TEST_INDEX)

test_node:
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) \
	tests/test_node.c \
	$(STACK_SRC) \
	$(LIBFT) \
	-o $(TEST_NODE)
	./$(TEST_NODE)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

tclean:
	rm -f $(TEST_NODE) $(TEST_INDEX)

.PHONY: all clean fclean re tclean
