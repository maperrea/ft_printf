# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maperrea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 18:04:28 by maperrea          #+#    #+#              #
#    Updated: 2020/02/06 22:27:18 by maperrea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.h inc
vpath %.c src
vpath %.c libft
vpath %.o obj

NAME		= libftprintf.a

SRCDIR		= src

SRCS		= $(notdir $(shell find $(SRCDIR)/*.c))

LIBSRC		= $(notdir $(shell find $(LIBDIR)/*.c))

OBJDIR		= obj

OBJS		= $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

LIBOBJS		= $(addprefix $(LIBDIR)/,$(LIBSRC:.c=.o))

INCDIR		= inc

LIB			= ft

LIBDIR		= libft

LIBINC		= libft

CC 			= gcc

RM			= rm -f

CFLAGS		= -Wall -Werror -Wextra

$(OBJDIR)/%.o: $(SRCDIR)/%.c
			$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBINC) -c $^ -o $@

all:		$(NAME)

$(OBJDIR):
			mkdir -p $(OBJDIR)

$(LIB):
			make -C libft

$(NAME):	$(LIB) $(OBJDIR) $(OBJS)
			ar rc $(NAME) $(OBJS) $(LIBOBJS) #$(LIBDIR)/lib$(LIB).a

a.out:		$(LIB)
			$(CC) $(CFLAGS) -fsanitize=address -I$(INCDIR) -I$(LIBINC) -L$(LIBDIR) -l$(LIB) $(addprefix $(SRCDIR)/,$(SRCS))

clean:
			$(RM) -r $(OBJDIR)
			make -C libft clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) a.out

re:			
			make -C libft fclean
			make fclean
			make all

.PHONY:		all clean fclean re
