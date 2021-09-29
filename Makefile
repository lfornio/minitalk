SERVER			= 	server
CLIENT			= 	client
SERVER_BONUS	= 	server_bonus
CLIENT_BONUS	= 	client_bonus
SRCS_SERVER		= 	server.c func.c
SRCS_CLIENT		= 	client.c func.c
SRCS_SERVER_B	= 	server_bonus.c func.c
SRCS_CLIENT_B	= 	client_bonus.c func.c
CC 				= 	gcc
FLAGS			=	-Wall -Wextra -Werror
INCLUDES		=	minitalk.h
OBJS_SERVER		=	$(SRCS_SERVER:.c=.o)
OBJS_CLIENT		=	$(SRCS_CLIENT:.c=.o)
OBJS_SERVER_B		=	$(SRCS_SERVER_B:.c=.o)
OBJS_CLIENT_B		=	$(SRCS_CLIENT_B:.c=.o)

.c.o: $(INCLUDE)
	$(CC) $(FLAGS)  -c $< -o $@

$(SERVER): $(OBJS_SERVER) $(INCLUDE)
	$(CC) $(OBJS_SERVER) -o $(SERVER)

$(CLIENT): $(OBJS_CLIENT) $(INCLUDE)
	$(CC) $(OBJS_CLIENT) -o $(CLIENT)

all : $(SERVER) $(CLIENT)

$(SERVER_BONUS): $(OBJS_SERVER_B) $(INCLUDE)
	$(CC) $(OBJS_SERVER_B) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJS_CLIENT_B) $(INCLUDE)
	$(CC) $(OBJS_CLIENT_B) -o $(CLIENT_BONUS)

bonus : $(SERVER_BONUS) $(CLIENT_BONUS)

clean :
	rm -f $(OBJS_SERVER)
	rm -f $(OBJS_CLIENT)
	rm -f $(OBJS_SERVER_B)
	rm -f $(OBJS_CLIENT_B)

fclean : clean
	rm -f $(SERVER)
	rm -f $(CLIENT)
	rm -f $(SERVER_BONUS)
	rm -f $(CLIENT_BONUS)

re : fclean all

.PHONY: all clean fclean re bonus
