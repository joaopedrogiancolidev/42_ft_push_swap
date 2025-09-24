# ------ Variáveis ------
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Diretórios
LIBFT_DIR = ../libft
FT_PRINTF_DIR = ../ft_printf
INC_DIR = includes

# Arquivos fonte
SRC_COMMON = main.c \
             stack_init.c \
             stack_utils.c \
             error_handling.c \
             sort_three.c \
             sort_small.c \
             sort_large.c

SRC_OPERATIONS = push.c \
                 swap.c \
                 rotate.c \
                 reverse_rotate.c

# Paths completos
SRC_MANDATORY = $(addprefix srcs/, $(SRC_COMMON)) \
                $(addprefix srcs/operations/, $(SRC_OPERATIONS))

# Objetos
OBJ_MANDATORY = $(SRC_MANDATORY:.c=.o)

# ------ Regras Principais ------
all: libs $(NAME)

$(NAME): $(OBJ_MANDATORY)
	@echo "Linkando $(NAME)..."
	$(CC) $(CFLAGS) $(OBJ_MANDATORY) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME)

%.o: %.c
	@echo "Compilando $<..."
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -c $< -o $@

libs:
	@echo "Compilando libft..."
	$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@echo "Compilando ft_printf..."
	$(MAKE) -C $(FT_PRINTF_DIR) --no-print-directory

clean:
	@echo "Limpando objetos..."
	rm -f $(OBJ_MANDATORY)
	$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	$(MAKE) -C $(FT_PRINTF_DIR) clean --no-print-directory

fclean: clean
	@echo "Limpando executável..."
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	$(MAKE) -C $(FT_PRINTF_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re libs