NAME			=	pipex

SRCS			=	pipex.c\
					command.c\
					ft_split.c\
					utils.c


SRCS_B			=	main.c\
					pipex_bonus.c\
					command_bonus.c\
					ft_split_bonus.c\
					utils_bonus.c\
					get_next_line.c\
					get_next_line_utils.c\

SRCS_DIR		=	src

SRCS_B_DIR		=	src_bonus

SOURCES			=	$(addprefix $(SRCS_DIR)/, $(SRCS))

SOURCES_B		=	$(addprefix $(SRCS_B_DIR)/, $(SRCS_B))

HEADER			=	$(SRCS_DIR)/pipex.h

HEADER_B		=	$(SRCS_B_DIR)/pipex_bonus.h

OBJ_PATH		=	obj

OBJS			=	$(SOURCES:$(SRCS_DIR)/%.c=$(OBJ_PATH)/%.o)

OBJS_B			=	$(SOURCES_B:$(SRCS_B_DIR)/%.c=$(OBJ_PATH)/%.o)

CC				=	gcc

RM				=	rm -f

CFLAGS			=	-Wextra -Werror -Wall -g

.PHONY			:	all clean fclean re bonus

all				:	$(NAME)

bonus			:
	@make OBJS="$(OBJS_B)" all

$(NAME)			:	$(OBJS)
	$(CC) $(FLAGS)  $^ -o $(NAME)


$(OBJ_PATH)/%.o	:	$(SRCS_DIR)/%.c $(HEADER)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_PATH)/%.o	:	$(SRCS_B_DIR)/%.c $(HEADER_B)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(FLAGS) -c $< -o $@

clean			:	
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)
	@rmdir  $(OBJ_PATH) 2> /dev/null || true


fclean			:	clean
	$(RM)  $(NAME)

re				: fclean all