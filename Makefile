SRCS = server.c client.c mt_utils.c
OBJ_FILES = ${SRCS:.c=.o}
SRCS_BNS = server_bonus.c client_bonus.c mt_utils.c
OBJ_FILES_BNS = ${SRCS_BNS:.c=.o}
NAME = minitalk.a
LIBFT_LIB = libft.a
FT_PRINTF_LIB = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${LIBFT_LIB}:
	cd ./libft && make

${FT_PRINTF_LIB}:
	cd ./ft_printf && make

%.o: %.c header.h
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJ_FILES} ${LIBFT_LIB} ${FT_PRINTF_LIB}
	$(CC) $(CFLAGS) client.o mt_utils.o ${LIBFT_LIB} ${FT_PRINTF_LIB} -o client
	$(CC) $(CFLAGS) server.o mt_utils.o ${LIBFT_LIB} ${FT_PRINTF_LIB} -o server
	ar rc ${NAME} ${OBJ_FILES}

%_bonus.o: %_bonus.c header_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: ${OBJ_FILES_BNS} ${LIBFT_LIB} ${FT_PRINTF_LIB}
	$(CC) $(CFLAGS) client_bonus.o mt_utils.o ${LIBFT_LIB} ${FT_PRINTF_LIB} -o client_bonus
	$(CC) $(CFLAGS) server_bonus.o mt_utils.o ${LIBFT_LIB} ${FT_PRINTF_LIB} -o server_bonus
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

.PHONY: re fclean clean all bonus