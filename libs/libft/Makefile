# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/09 17:13:28 by jonkim            #+#    #+#              #
#    Updated: 2018/01/09 18:40:22 by jonkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memcpy.c          \
      ft_memccpy.c         \
      ft_memmove.c         \
      ft_memchr.c          \
      ft_memcmp.c          \
      ft_strncpy.c         \
      ft_strncat.c         \
      ft_strlcat.c         \
      ft_strrchr.c         \
      ft_strstr.c          \
      ft_strnstr.c         \
      ft_strcmp.c          \
      ft_strncmp.c         \
      ft_isalpha.c         \
      ft_isdigit.c         \
      ft_isalnum.c         \
      ft_isascii.c         \
      ft_isprint.c         \
      ft_tolower.c         \
      ft_memdel.c          \
      ft_strdel.c          \
      ft_strclr.c          \
      ft_striter.c         \
      ft_striteri.c        \
      ft_strmap.c          \
      ft_strmapi.c         \
      ft_strequ.c          \
      ft_strnequ.c         \
      ft_strsub.c          \
      ft_strtrim.c         \
      ft_strsplit.c        \
      ft_putendl.c         \
      ft_putnbr.c          \
      ft_putchar_fd.c      \
      ft_putstr_fd.c       \
      ft_putendl_fd.c      \
      ft_putnbr_fd.c       \
      ft_lstnew.c          \
      ft_lstdelone.c       \
      ft_lstdel.c          \
      ft_lstadd.c          \
      ft_lstiter.c         \
      ft_lstmap.c          \
	  ft_str_upcase.c      \
	  ft_str_lowcase.c     \
	  ft_atoi_base.c       \
	  ft_itoa_base.c       \
	  get_next_line.c      \
	  ft_check.c           \
	  ft_init.c            \
	  ft_printf.c          \
	  ft_set_i.c           \
	  ft_set_xi.c          \
	  ft_work_int.c        \
	  ft_work_xint.c       \
	  ft_work_uint.c       \
	  ft_work_wchr.c       \
	  ft_work_wstr.c       \
	  ft_set_lcs.c         \
	  ft_set_ls_subfunc.c  \
	  ft_set_ptraddr.c     \
	  ft_set_percent.c     \
	  ft_set_general.c     \
	  ft_set_wcs.c         \
	  ft_asterisk.c        \
	  libft_func1.c        \
	  libft_func2.c        \
	  libft_func3.c        \
	  libft_func4.c        \
	  libft_func5.c

OBJ = $(SRC:.c=.o)

SRC_DIR = srcs

OBJ_DIR = objs

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))

WFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(OBJS): $(SRCS)
	@/bin/mkdir -p $(OBJ_DIR)
	@gcc -c $(WFLAGS) $(SRCS) -I includes
	@/bin/mv $(OBJ) $(OBJ_DIR)/

$(NAME): $(OBJS)
	@ar rc $@ $^

clean:
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
