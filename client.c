#include "minitalk.h"

int	send(pid_t pid, char c)
{
	int	i;

	i = 128;
	while (i >= 1)
	{
		if (c & i)
		{
			if (kill(pid, SIGUSR1) == -1)
				error_exit("Signal error");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error_exit("Signal error");
		}
		usleep(100);
		i /= 2;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*mssg;
	int		i;

	if (argc < 3)
		error_exit("Too few arguments\nUsage: ./client [server pid] [message]");
	else if (argc > 3)
		error_exit("Too many arguments\nUsage: ./client [server pid] [message]");
	else if (ft_atoi(argv[1]) <= 0)
		error_exit("Invalid Process ID");
	pid = ft_atoi(argv[1]);
	mssg = argv[2];
	i = 0;
	while (mssg[i] != '\0')
		send(pid, mssg[i++]);
	send(pid, '\n');
	return (0);
}
