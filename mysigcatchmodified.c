#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int counter=0;

// SIGINT signal handler
void custom_sigint_handler(int sig)
{
	printf("\nSIGINT signal caught with code: %d\n", sig);
	if (counter>0)
	{
		signal(SIGINT, SIG_DFL);
		exit(0);
	}
	counter++;
}

int main()
{
//	int counter=0;

	// Registers the sigint handler
	if (signal(SIGINT, custom_sigint_handler) == SIG_ERR)
	{
		perror("signal");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		sleep(2);
	}

	return 0;
}
