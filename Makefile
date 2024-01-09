SRCS = server.c client.c mt_utils.c
OBJ_FILES = ${SRCS:.c=.o}
SRCS_BNS = server_bonus.c client_bonus.c
OBJ_FILES_BNS = ${SRCS_BNS:.c=.o}
NAME = minitalk.a
LIBFT_LIB = libft.a
FT_PRINTF_LIB = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : ${NAME} client server

${LIBFT_LIB}:
	cd ./libft && make

${FT_PRINTF_LIB}:
	cd ./ft_printf && make

${NAME} : ${OBJ_FILES}
	ar rc ${NAME} ${OBJ_FILES}

%.o: %.c header.h
	$(CC) $(CFLAGS) -c $< -o $@

client : client.o mt_utils.o ${LIBFT_LIB} ${FT_PRINTF_LIB}
	$(CC) $(CFLAGS) $^ -o $@

server : server.o mt_utils.o ${LIBFT_LIB} ${FT_PRINTF_LIB}
	$(CC) $(CFLAGS) $^ -o $@

client_bonus : client_bonus.o mt_utils.o ${LIBFT_LIB} ${FT_PRINTF_LIB}
	$(CC) $(CFLAGS) $^ -o $@

server_bonus : server_bonus.o mt_utils.o ${LIBFT_LIB} ${FT_PRINTF_LIB}
	$(CC) $(CFLAGS) $^ -o $@

%_bonus.o: %_bonus.c header_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus : client_bonus server_bonus ${OBJ_FILES_BNS}
	ar rc ${NAME} ${OBJ_FILES_BNS}

clean :
	rm -f ${OBJ_FILES} ${OBJ_FILES_BNS}
	cd ./libft && make clean
	cd ./ft_printf && make clean

fclean : clean
	rm -f ${NAME} client server client_bonus server_bonus libft.a libftprintf.a
	cd ./libft && make fclean
	cd ./ft_printf && make fclean

re : fclean all

.PHONY: re fclean clean all bonus server client server_bonus client_bonus