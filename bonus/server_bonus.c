#include "minitalk_bonus.h"

void	ft_sigaction(int sig, siginfo_t *info, void *ucontext)
{
	static int	ch;
	static int	power;

	(void)ucontext;
	if (!power)
		power = 128;
	if (sig == SIGUSR1)
		ch += power;
	power /= 2;
	if (power == 0)
	{
		if (ch == 0x0a)
		{
			if (kill(info->si_pid, SIGUSR1) == -1)
				error_exit("Error");
		}
		ft_putchar_fd((char)ch, 1);
		power = 128;
		ch = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	if (pid < 0)
		error_exit("Invalid Process ID");
	ft_putstr_fd("\x1B[32mProcess ID: \x1B[0m", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_sigaction;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		error_exit("Invalid value");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		error_exit("Invalid value");
	while (1)
		pause();
}
