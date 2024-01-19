# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoser <mmoser@student.codam.nl>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 14:37:27 by mmoser            #+#    #+#              #
#    Updated: 2024/01/19 16:14:54 by mmoser           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
B_NAME		:= checker

LIBS		:= ft
LIBS_TARGET	:= libft/libft.a

CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra -g 
LINKFLAGS	:= $(addprefix -L ,$(dir $(LIBS_TARGET))) $(addprefix -l ,$(LIBS))
RM			:= rm -rf

SRC_DIR		:= src
BUILD_DIR	:= .build

# ---------------------------------------------------------------------------- #
PS_DIR		:= push_swap
CO_DIR		:= common
CH_DIR		:= checker
# ---------------------------------------------------------------------------- #
PS_SRCS		:= main.c sort_alg1.c sort_alg2.c sort_alg3.c
CO_SRCS		:= parsing.c lst_ops1.c lst_ops2.c helper_foos1.c helper_foos2.c \
			   sort_ops1.c sort_ops2.c sort_ops3.c
CH_SRCS		:= main.c parse_and_check.c
# ---------------------------------------------------------------------------- #
PS_SRCS		:= $(PS_SRCS:%=$(SRC_DIR)/$(PS_DIR)/%)
CO_SRCS		:= $(CO_SRCS:%=$(SRC_DIR)/$(CO_DIR)/%)
CH_SRCS		:= $(CH_SRCS:%=$(SRC_DIR)/$(CH_DIR)/%)
# ---------------------------------------------------------------------------- #
PS_OBJS		:= $(PS_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
CO_OBJS		:= $(CO_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
CH_OBJS		:= $(CH_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
# ---------------------------------------------------------------------------- #

all: $(NAME)

bonus: $(B_NAME)

$(NAME): $(PS_OBJS) $(CO_OBJS) $(LIBS_TARGET)
	@printf "\n"
	$(CC) $(PS_OBJS) $(CO_OBJS) $(LINKFLAGS) -o $(NAME)
	@printf "$(CREATED)" $@ $(CUR_DIR)

$(B_NAME): $(CH_OBJS) $(CO_OBJS) $(LIBS_TARGET)
	$(CC) $(CH_OBJS) $(CO_OBJS) $(LINKFLAGS) -o $(B_NAME)
	@printf "$(CREATED)" $@ $(CUR_DIR)

%.a:
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(dir $(LIBS_TARGET)) clean
	$(RM) $(BUILD_DIR)
	@printf "$(REMOVED)" $(BUILD_DIR) $(CUR_DIR)

fclean: clean
	$(MAKE) -C $(dir $(LIBS_TARGET)) fclean
	$(RM) $(NAME) $(B_NAME)
	@printf "$(REMOVED)" $(NAME) $(CUR_DIR)
	@printf "$(REMOVED)" $(B_NAME) $(CUR_DIR)

re:
	$(MAKE) fclean
	$(MAKE) all

info-%:
	$(MAKE) --dry-run --always-make $*

print-%:
	$(info $($*))

re: clean fclean re

# ----------------------------------- colors --------------------------------- #

BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

# ----------------------------------- messages ------------------------------- #

CUR_DIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
REMOVED	:= $(MAGENTA) $(BOLD) REMOVED %s (%s) $(RESET)\n\n
CREATED	:= $(GREEN) $(BOLD) CREATED %s (%s) $(RESET)\n\n
UPDATED	:= $(GREEN) $(BOLD) CREATED OR UPDATED %s (%s) $(RESET)\n\n
