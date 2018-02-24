# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 21:56:14 by slynn-ev          #+#    #+#              #
#    Updated: 2018/02/03 12:53:44 by slynn-ev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = SRC

SRC_NAME = ft_printf/ft_printf.c \
ft_printf/ft_putbase.c \
ft_printf/num_flags.c \
ft_printf/num_flags_cont.c \
ft_printf/num_printers.c \
ft_printf/print_chars.c \
ft_printf/print_numbers.c \
ft_printf/unicode.c \
ft_printf/fd.c \
libft/ft_atoi.c \
libft/ft_str_to_intdata.c \
libft/ft_bzero.c \
libft/ft_add_charpointer.c \
libft/ft_put_inta.c \
libft/ft_intdebug.c \
libft/ft_isalnum.c \
libft/ft_isalpha.c \
libft/ft_isascii.c \
libft/ft_isdigit.c \
libft/ft_isprint.c \
libft/ft_atoi_base.c \
libft/ft_abs.c \
libft/ft_itoa.c \
libft/ft_lstadd.c \
libft/ft_lstaddend.c \
libft/ft_lstdel.c \
libft/ft_lstdelone.c \
libft/ft_lstiter.c \
libft/ft_lstmap.c \
libft/ft_lstnew.c \
libft/ft_lstnew_ptr.c \
libft/ft_lsttstr_del.c \
libft/ft_memalloc.c \
libft/ft_memccpy.c \
libft/ft_memchr.c \
libft/ft_memcmp.c \
libft/ft_memcpy.c \
libft/ft_memdel.c \
libft/ft_memmove.c \
libft/ft_memset.c \
libft/ft_print_list.c \
libft/ft_power.c \
libft/ft_putchar.c \
libft/ft_putchar_fd.c \
libft/ft_putendl.c \
libft/ft_putendl_fd.c \
libft/ft_putnbr.c \
libft/ft_putnbr_fd.c \
libft/ft_putstr.c \
libft/ft_putstr_fd.c \
libft/ft_putstrn.c \
libft/ft_strcat.c \
libft/ft_strchr.c \
libft/ft_strclr.c \
libft/ft_strcmp.c \
libft/ft_strcpy.c \
libft/ft_strdebug.c \
libft/ft_strdel.c \
libft/ft_strdup.c \
libft/ft_strequ.c \
libft/ft_striter.c \
libft/ft_striteri.c \
libft/ft_strjoin.c \
libft/ft_strjoin_free.c \
libft/ft_strlcat.c \
libft/ft_strlen.c \
libft/ft_strmap.c \
libft/ft_strmapi.c \
libft/ft_strncat.c \
libft/ft_strncmp.c \
libft/ft_strncpy.c \
libft/ft_strnequ.c \
libft/ft_strnew.c \
libft/ft_strnstr.c \
libft/ft_strrchr.c \
libft/ft_strsplit.c \
libft/ft_strstr.c \
libft/ft_strsub.c \
libft/ft_tolower.c \
libft/ft_toupper.c \
libft/ft_unicode_putchar.c \
libft/get_num_length.c \
get_next_line/get_next_line.c \

CPPFLAGS = -I Includes

FLAGS = -Wall -Wextra -Werror -O3

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = obj

DEPS = Includes/libft.h \
Includes/ft_printf.h \
Includes/get_next_line.h \

NAME = libft.a

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@echo "###\nlibftprintf.a compiled"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(DEPS)
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(dir $(OBJ))
	@gcc $(FLAGS) -o $@ -c $< $(CPPFLAGS)
	@echo "#" | tr -d '\n'

	
clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

