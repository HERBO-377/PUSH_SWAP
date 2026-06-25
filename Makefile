NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I include -I $(LIBFT_DIR)

SRC_DIR = src

HEADERS = \
	include/push_swap.h \
	include/bench_struct.h \
	include/flag_struct.h \
	include/node_struct.h \
	include/parse_struct.h \
	include/sort_struct.h \
	$(LIBFT_DIR)/libft.h \
	$(LIBFT_DIR)/ft_printf.h

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

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT) $(HEADERS) Makefile
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
