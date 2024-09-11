# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pudry <pudry@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 11:40:33 by paul              #+#    #+#              #
#    Updated: 2024/09/11 08:56:23 by pudry            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET = \\033[0m
GREEN = \\033[1;32m
BLUE = \033[1;34m
PURPLE = \033[35m
INCLUDES = includes/

# compilateur
CC = gcc
# flags du compilateur
CFLAGS = -Wall -Wextra -Werror
# name du fichier / dossier retourné
NAME = libft.a

# source : nom des fichiers
SRC = $(wildcard src/*.c)
BONUS_SRC = $(wildcard src/bonus/*.c)

# Reprise des noms du fichier et remplacement du .c en .o
OBJ = $(SRC:src/%.c=objet/%.o)
BONUS_OBJ = $(BONUS_SRC:src/bonus/%.c=objet/bonus/%.o)

# cette ligne dit comment générer le fichier name avec les objets
# c'est une fonction.

# fonction pour générer le fichier Libft.a
all: $(NAME)
	@echo "${GREEN}Libft compilation success"
	@echo "${BLUE}for header and librairie"
	@echo "-I $(PWD)/includes -L $(PWD)/$(NAME) -lft"
	@echo "${PURPLE}#include \"libft.h\"${RESET}"

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

bonus: $(NAME) $(BONUS_OBJ)
	@ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)
	@echo "${GREEN}Libft compilation success with bonus"
	@echo "${BLUE}for header and librairie"
	@echo "-I $(PWD)/includes -L $(PWD)/$(NAME) -lft"
	@echo "${PURPLE}#include \"libft.h\"${RESET}"

# fonction nettoyage fichier objet
clean:
	@rm -rf objet/
	@echo "${GREEN}Libft clean${RESET}"

# nettoyage fichier objet + delete libft.a
fclean: clean
	@rm -f $(NAME)
	@echo "${GREEN}Libft fclean${RESET}"

# delete all file et compile again
re: fclean all

# règle implicite pour compiler .c en .o
objet/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

objet/bonus/%.o: src/bonus/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)


# Ligne pour éviter que ces fonctions puissent être considérées comme fichier
.PHONY: clean fclean all re bonus
