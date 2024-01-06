#ifndef CLIENT_H
#define CLIENT_H

#include <unistd.h>
#include <stdlib.h>

int         ft_atoi(const char *str);
int         ft_printf(const char *format, ...);
void        ft_putnbr(long d, int *ptr_c);
void        ft_putchar(char c, int *ptr_c);
void        isstring(const char *string, int *ptr_c);
void        per_p(void *ptr_ul, int *ptr_c);
void        per_x(unsigned int num, char format, int *ptr_c);
int         ft_atoi_base(char *str);
size_t      ft_strlen(const char *s);

#endif

