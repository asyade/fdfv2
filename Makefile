CC = gcc

NAME = fdf

PATH_SRC = srcs/ srcs/parsing/

DIRS =	obj/ \
		obj/parsing \
		obj/vector \
		obj/render \

SRC = srcs/main.c \
	  srcs/parsing/fdf_parse_utils.c \
	  srcs/parsing/fdf_parse.c \
	  srcs/render/render.c \
	  srcs/render/render_loop.c \
	  srcs/render/draw.c \
	  srcs/render/hooks.c \
	  srcs/vector/vec.c \
	  srcs/vector/quaternion.c \
	  srcs/vector/projection.c \

OBJ = $(patsubst $(PATH_SRC)/%.c, obj/%.o, $(SRC))

FLAGS = -Wall -Wextra -Werror -g

LIBS = -L./libft -lft

HEADERS = -I includes/ -I libft/includes -L./minilibx -lmlx -I./minilibx -lm -lpthread -framework AppKit -framework cocoa -framework openGL
 
DEPTHS = Makefile includes/vector.h includes/structs.h includes/fdf.h libft/includes/libft.h

.SILENT :

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) $(OBJ) libft/libft.a -o $(NAME) $(HEADERS) $(FLAGS)
	echo "\033[33mCreating  \033[32m[✔] \033[0m$(NAME)"

obj/%.o : $(PATH_SRC)/%.c $(DEPTHS)
	mkdir -p $(DIRS)
	$(CC) -c $< -o $@ $(FLAGS) $(HEADERS) 
	echo "\033[33mCompiling \033[32m[✔] \033[0m$<"

.PHONY : clean fclean

clean :
	make -C libft/ clean
	/bin/rm -rf obj/
	echo "\033[31mRemoving  \033[32m[✔] \033[0mObject files"

fclean : clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)
	echo "\033[31mRemoving  \033[32m[✔] \033[0m$(NAME)"

re : fclean all
