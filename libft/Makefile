CC = gcc

NAME = libft.a

PATH_SRC = src

ODIRS = obj/

SRC = src/ft_printf.c \
	   src/parse_exp.c \
	   src/ft_printf_fn.c \
	   src/print_uint.c \
	   src/print_char.c \
	   src/print_escape.c \
	   src/print_hex_ptr.c \
	   src/print_int.c \
	   src/print_octal.c \
	   src/print_str.c \
	   src/buffer.c \
	   src/padding.c \
	   src/pf_putfn1.c \
	   src/pf_putfn2.c \
	   src/print_long.c \

OBJ = $(patsubst $(PATH_SRC)/%.c, obj/%.o, $(SRC))

FLAGS = -Wall -Wextra -Werror

LIBS = -L./libft -lft

H_FILES = includes/libft.h includes/ft_printf.h

HEADERS = -I includes/

all : $(NAME)

obj/%.o : $(PATH_SRC)/%.c $(H_FILES)
	mkdir -p $(ODIRS)
	@$(CC) $(FLAGS) -c $< -o $@ -I includes/ 
	echo "\033[33mCompiling \033[32m[✔] \033[0m$<"

$(NAME) : $(OBJ)
	make -C libft/
	ar rc $(NAME) $(OBJ) libft/*.o
	ranlib $(NAME)

clean :
	make -C libft/ clean
	/bin/rm -rf obj/
	echo "\033[31mRemoving  \033[32m[✔] \033[0mObject files"

fclean : clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)
	echo "\033[31mRemoving  \033[32m[✔] \033[0m$(NAME)"

re : fclean all

valgrind : all
	gcc -g main.c -L. -lftprintf -I includes/
	valgrind --leak-check=full ./a.out

.PHONY : valgrind clean fclean re
