INCLUDES = -Ilibft/Includes -I.

LIB = libft

LIB.A = libft.a

CH_SRC_NAME = checker/main.c

P_SRC_NAME = push_swap/main.c push_swap/a_functions.c push_swap/b_functions.c

CO_SRC_NAME = commands/commands.c

SRC_PATH = src

CH_OBJ_NAME = $(CO_SRC_NAME:.c=.o) $(CH_SRC_NAME:.c=.o)

P_OBJ_NAME = $(CO_SRC_NAME:.c=.o) $(P_SRC_NAME:.c=.o)

OBJ_PATH = obj

CH_SRC = $(addprefix $(SRC_PATH)/, $(CH_SRC_NAME))

P_SRC = $(addprefix $(SRC_PATH)/, $(P_SRC_NAME))

CO_SRC = $(addprefix $(SRC_PATH)/ $(CO_SRC_NAME))

CH_OBJ = $(addprefix $(OBJ_PATH)/, $(CH_OBJ_NAME))

P_OBJ = $(addprefix $(OBJ_PATH)/, $(P_OBJ_NAME))

NAME_C = checker

NAME_P = push_swap

FLAGS = -Wall -Wextra -Werror

all : library $(NAME_C) $(NAME_P)

library :
	make -C $(LIB)

$(NAME_C) : $(CH_OBJ)
	gcc -o $@ $(CH_OBJ) $(INCLUDES) $(LIB)/$(LIB.A) -g

$(NAME_P) : $(P_OBJ)
	gcc -o $@ $(P_OBJ) $(INCLUDES) $(LIB)/$(LIB.A) -g

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(dir $(P_OBJ))
	gcc -o $@ -c $< $(INCLUDES) $(FLAGS)

clean :
	rm -fr $(OBJ_PATH)
	make clean -C $(LIB)

fclean :
	rm -f $(NAME_C)
	rm -f $(NAME_P)
	make fclean -C $(LIB)

re : fclean all
