#include "header.h"

static void	handler(int signal)
{
	static int	bit;
	static char	tmp;

	if (signal == SIGUSR1)
		tmp |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(tmp, 1);
		bit = 0;
		tmp = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t server_pid;

	(void)argv;
	if (argc != 1)
		return (0);
 	server_pid = getpid();
	ft_putnbr_fd(server_pid, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}

/*
 1. main
  -> 리턴타입 void로?
  -> argc 부분 수정하기
  -> 

 2. handler
 3. pid print  
*/