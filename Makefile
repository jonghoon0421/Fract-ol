# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/09 17:16:00 by jonkim            #+#    #+#              #
#    Updated: 2018/02/17 16:58:49 by jonkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c			\
	  ft_error.c		\
	  ft_mandelbrot.c	\
	  ft_burningship.c	\
	  ft_julia.c		\
	  ft_tricorn.c		\
	  ft_newton3.c		\
	  ft_newton4.c		\
	  ft_no_complex.c	\
	  ft_complex.c		\
	  ft_sine.c			\
	  ft_window.c		\
	  ft_init.c			\
	  ft_color.c

OBJ = $(SRC:.c=.o)
MLX = -L $(MLXDIR) -lmlx -framework OpenGL -framework Appkit

SRCDIR = srcs
OBJDIR = objs
LIBDIR = libs/libft
MLXDIR = libs/mlx

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))
LIBS = $(LIBDIR)/libft.a $(MLX)
HEADER = -I includes -I $(LIBDIR)/includes -I $(MLXDIR)

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

NAME = fractol

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(HEADER) $< -o $@

$(NAME): $(OBJS)
	@make -C $(MLXDIR)
	@make -C $(LIBDIR)
	@$(CC) $(OBJS) $(LIBS) -o $@ -lpthread
	@echo "\033[1;32m[make - all] DONE\033[0m"

clean:
	@/bin/rm -rf $(OBJDIR)
	@make -C $(MLXDIR) clean
	@make -C $(LIBDIR) clean
	@echo "\033[1;31m[make - clean] DONE\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@rm -f $(LIBDIR)/libft.a
	@echo "\033[1;31m[make - fclean] DONE\033[0m"

re: fclean all
