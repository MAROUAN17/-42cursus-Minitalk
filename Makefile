SRCS = ft_printf.c help_functions.c is_string.c per_p.c per_x.c ft_putnbr.c ft_putchar.c
OBJ_FILES = ${SRCS:.c=.o}
NAME = minitalk.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c header.h
	$(CC) $(CFLAGS) -c $< -o $@

all : ${NAME} client server

${NAME} : ${OBJ_FILES}
	ar rc ${NAME} ${OBJ_FILES}

client : client.o ${NAME}
	$(CC) $(CFLAGS) $^ -o $@

server : server.o ${NAME}
	$(CC) $(CFLAGS) $^ -o $@

clean :
		rm -f ${OBJ_FILES} client.o server.o

fclean : clean
		rm -f ${NAME} client server

re : fclean all

.PHONY: re fclean clean all bonus