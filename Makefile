
NAME_SERV	=	server

NAME_CL		=	client

NAME_BS		=	server_bonus

NAME_BC		=	client_bonus

HEADER		=	minitalk.h

HEADER_B	=	bonus/minitalk_bonus.h

SRCS_SERV	=	server.c

SRCS_CL		=	client.c

SRCS		=	utils.c

SRCS_BS		=	bonus/server_bonus.c

SRCS_BC		=	bonus/client_bonus.c

SRCS_B		=	bonus/utils_bonus.c

OBJS_SERV	=	$(SRCS_SERV:.c=.o)

OBJS_CL		=	$(SRCS_CL:.c=.o)

OBJS_BS		=	$(SRCS_BS:.c=.o)

OBJS_BC		=	$(SRCS_BC:.c=.o)

OBJS		=	$(SRCS:.c=.o)

OBJS_B		=	$(SRCS_B:.c=.o)

CC			=	gcc -Wall -Werror -Wextra

RM			=	rm -f

all:			$(NAME_SERV) $(NAME_CL)

$(NAME_SERV):	$(OBJS_SERV) $(OBJS) $(HEADER)
				@$(CC) $(OBJS_SERV) $(OBJS) -o $(NAME_SERV)

$(NAME_CL):		$(OBJS_CL) $(OBJS) $(HEADER)
				@$(CC) $(OBJS_CL) $(OBJS) -o $(NAME_CL)

bonus:			$(NAME_BS) $(NAME_BC)

$(NAME_BS):		$(OBJS_BS) $(OBJS_B) $(HEADER_B)
				@$(CC) $(OBJS_BS) $(OBJS_B) -o $(NAME_BS)

$(NAME_BC):		$(OBJS_BC) $(OBJS_B) $(HEADER_B)
				@$(CC) $(OBJS_BC) $(OBJS_B) -o $(NAME_BC)

clean:
				$(RM) $(OBJS_SERV) $(OBJS_CL) $(OBJS) $(OBJS_BS) $(OBJS_BC) $(OBJS_B)

fclean:			clean
				$(RM) $(NAME_SERV) $(NAME_CL) $(RM) $(NAME_BS) $(NAME_BC)

re:				fclean all

.PHONY:			all clean fclean re bonus