# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 01:34:53 by greus-ro          #+#    #+#              #
#    Updated: 2024/07/01 23:22:22 by gabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET	= \033[0;39m
GRAY    = \033[0;90m
RED     = \033[0;91m
GREEN   = \033[0;92m
YELLOW  = \033[0;93m
BLUE    = \033[0;94m
MAGENTA = \033[0;95m
CYAN    = \033[0;96m
WHITE   = \033[0;97m

OBJ_DIR	=./obj
SRC_DIR	=./src
INC_DIR	=./inc

NAME	=libft.a
CFLAGS	=-Wall -Wextra -Werror
DFLAGS 	=-MMD -MP

ifdef CSANITIZE
	SANITIZE_FLAGS = -g -fsanitize=$${CSANITIZE}
endif 

# The bash variables are referenced as $$Whatever
define compile
    printf "%b%-46b" "$(BLUE)compiling " "$(CYAN)$(@F)$(RESET)"; \
    $(1) > /dev/null; \
    RESULT=$$?; \
    if [ $$RESULT -ne 0 ]; then \
        printf "%b\n" "$(RED)[✗]$(RESET)"; \
    else  \
        printf "%b\n" "$(GREEN)[✓]$(RESET)"; \
    fi; \
    [ $$RESULT -eq 0 ]
endef

define link
	printf "%b%-48b" "$(YELLOW)linking " "$(CYAN)$(@F)$(RESET)"; \
    $(1) > /dev/null; \
    RESULT=$$?; \
    if [ $$RESULT -ne 0 ]; then \
        printf "%b\n" "$(RED)[✗]$(RESET)"; \
    else  \
        printf "%b\n" "$(GREEN)[✓]$(RESET)"; \
    fi; \
    [ $$RESULT -eq 0 ]
endef

SRC_FILES		=	ft_atoi				\
					ft_atol				\
					ft_bzero			\
					ft_calloc			\
					ft_dtoh				\
					ft_iputchar_fd		\
					ft_iputendl_fd		\
					ft_iputnbr_fd		\
					ft_iputstr_fd		\
					ft_isalnum			\
					ft_isalpha			\
					ft_isascii			\
					ft_isdigit			\
					ft_islower			\
					ft_isupper			\
					ft_isprint			\
					ft_itoa				\
					ft_memchr			\
					ft_memcmp			\
					ft_memcpy			\
					ft_memmove			\
					ft_memset			\
					ft_putchar_fd		\
					ft_putendl_fd		\
					ft_putnbr_fd		\
					ft_putstr_fd		\
					ft_sfree			\
					ft_split			\
					ft_strchr			\
					ft_strdup			\
					ft_striteri			\
					ft_strjoin			\
					ft_strlcat			\
					ft_strlcpy			\
					ft_strlen			\
					ft_strmapi			\
					ft_strncmp			\
					ft_strcmp			\
					ft_strnstr			\
					ft_strrchr			\
					ft_istrchr 			\
					ft_strtrim			\
					ft_substr			\
					ft_tolower			\
					ft_toupper			\
					ft_utoa

BONUS_SRC_FILES=	ft_lstadd_front_bonus	\
					ft_lstadd_back_bonus	\
					ft_lstclear_bonus		\
					ft_lstdelone_bonus		\
					ft_lstiter_bonus		\
					ft_lstlast_bonus		\
					ft_lstmap_bonus			\
					ft_lstnew_bonus			\
					ft_lstsize_bonus		


SRC	=	$(addprefix ${SRC_DIR}/, $(addsuffix .c, ${SRC_FILES} ${BONUS_SRC_FILES}))
OBJ	=	$(addprefix ${OBJ_DIR}/, $(addsuffix .o, ${SRC_FILES} ${BONUS_SRC_FILES}))
DEP = 	$(addprefix ${DEP_DIR}/, $(addsuffix .d, ${SRC_FILES} ${BONUS_SRC_FILES}))

all:${NAME}

${NAME}: ${OBJ} 
	@$(call link, ar -rcs ${NAME} ${OBJ})
	
${OBJ_DIR}/%.o:${SRC_DIR}/%.c  Makefile
	@mkdir -p $(dir $@)
	@$(call compile, ${CC} ${CFLAGS} ${DFLAGS} ${SANITIZE_FLAGS} -c $< -I ${INC_DIR} -o $@)

clean:
	@rm -f ${OBJ_DIR}/*.o
	@rm -f ${OBJ_DIR}/*.d
	@printf "%-53b%b" "$(GRAY)$(@):" "$(GREEN)[✓]$(RESET)\n"

fclean: clean 
	@rm -f ${NAME}
	@printf "%-53b%b" "$(GRAY)$(@):" "$(GREEN)[✓]$(RESET)\n"	

re: fclean all

norm:
	@norminette $(SRC_DIR) $(INC_DIR) | grep -v OK \
		|| echo "$(GREEN)Norminette: OK $(RST)"

-include ${DEP}

.PHONY= all clean fclean re norm
