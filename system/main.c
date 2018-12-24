/*  main.c  - main */

#include <xinu.h>
#include <stdio.h>

sid32 gsem;			/* Declaring a Semaphore - global */

int main(int argc, char **argv)
{
	uint32 retval;
	gsem = semcreate(0);	/* Initializing the semaphore with 0 */

	resume(create(shell, 8192, 50, "shell", 1, CONSOLE));

	/* Wait for shell to exit and recreate it */

	recvclr();
	while (TRUE) {
		retval = receive();
		kprintf("\n\n\rMain process recreating shell\n\n\r");
		resume(create(shell, 4096, 1, "shell", 1, CONSOLE));
	}
	while (1);

	return OK;
}
