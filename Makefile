NAME			=	pipex

SRCS			=	pipex.c

SRCS_DIR		=	src

SOURCES			= $(addprefix $(SRCS_DIR)/, $(SRCS))


HEADER			=	$(SRCS_DIR)/pipex.h

OBJ_PATH		=	obj

OBJS			=	$(SOURCES:$(SRCS_DIR)/%.c=$(OBJ_PATH)/%.o)

CC				=	gcc

RM				=	rm -f

CFLAGS			=	-Wextra -Werror -Wall -g

.PHONY			:	all clean fclean re

all				:	$(NAME) 

$(NAME)			:	$(HEADER) $(OBJS)
	$(CC) $(FLAGS) $(SOURCES) -o $(NAME)


$(OBJ_PATH)/%.o	:	$(SRCS_DIR)/%.c $(HEADER)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(FLAGS) -c $< -o $@

clean			:	
	$(RM) $(OBJS)
	@rmdir  $(OBJ_PATH) 2> /dev/null || true


fclean			:	clean
	$(RM)  $(NAME)

re				: fclean all