
NAME			=	ft_debug.a

OUTPUT			?=	a.out

TEST			=	test.out

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

RESET			=	\033[0m
ICYAN			=	\033[3;36m

SRC_DIR			=	src
SRCS			=	$(wildcard $(SRC_DIR)/*.c)

OBJ_DIR			=	obj
OBJS			=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all:				$(NAME)

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					@echo "$(ICYAN)Compiling $<$(RESET)"
					@$(CC) $(CFLAGS) -c $< -o $@ -D OUTPUT='"$(OUTPUT)"'

$(NAME):			$(OBJ_DIR) $(OBJS)
					@echo "$(ICYAN)Linking $@$(RESET)"
					@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)

clean:
					@echo "$(ICYAN)Cleaning objects$(RESET)"
					@$(RM) $(OBJ_DIR)

fclean:				clean
					@echo "$(ICYAN)Cleaning $(NAME)$(RESET)"
					@$(RM) $(NAME)
					@echo "$(ICYAN)Cleaning $(TEST)$(RESET)"
					@$(RM) $(TEST)

re:					fclean all

test:				fclean
					@$(MAKE) OUTPUT=$(TEST)
					@echo "$(ICYAN)Compiling $@"
					@$(CC) $(CFLAGS) test/main.c $(NAME) -o $(TEST) \
						&& echo "\nRunning $@\n$(RESET)" \
						&& ./$(TEST) foo bar

.PHONY:				all clean fclean re test
