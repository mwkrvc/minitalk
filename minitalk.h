#ifndef MINITALK_H
# define MINITALK_H

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
int		error_exit(char *error);

#endif