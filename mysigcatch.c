#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// SIGINT signal handler
void sigint_handler()
{
	printf("\nSIGINT signal caught!\n");
	exit(0);
}

int main()
{
	// Catches the sigint
	if (signal(SIGINT, sigint_handler) == SIG_ERR)
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
