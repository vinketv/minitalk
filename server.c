// server.c
#include "minitalk.h"

void ft_handler(int signal, siginfo_t *info, void *context)
{
    static int bit = 0;
    static char char_buffer = 0;

    (void)context;
    if (signal == SIGUSR1)
        char_buffer |= (0x01 << bit);
    bit++;
    if (bit == 8)
    {
        write(1, &char_buffer, 1);  // Utilisation de write au lieu de printf pour plus de fiabilité
        bit = 0;
        char_buffer = 0;
        kill(info->si_pid, SIGUSR2);  // Confirmation au client
    }
}

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	pid = getpid();
	printf("PID : %d\n", pid);
	printf("Waiting for a message...\n");

	sig.sa_sigaction = ft_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);

	while (1)
	{
		pause();  // Attend un signal
	}
	return (0);
}
