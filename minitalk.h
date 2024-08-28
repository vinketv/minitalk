#ifndef MINITALK_H
# define MINITALK_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *source);
int     ft_printaddress(void *x, int *length, int flag);
int     ft_putnbr(int num, int *length);
int     ft_putnbr_unsigned(unsigned int n, int *length);
int     ft_putchar(char c, int *length);
int     ft_putstr(char *str, int *length);
int     ft_printhexa(unsigned int n, int *length, char type);
int     format_handler(const char *format, va_list args, int *length);
int     ft_printf(const char *format, ...);
int     ft_atoi(const char *nptr);

#endif