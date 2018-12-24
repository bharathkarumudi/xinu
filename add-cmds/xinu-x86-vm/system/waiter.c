/* waiter.c - waiter */
#include<xinu.h>

extern sid32 gsem;	/* Using the global semaphore variable, declared in main.c */

/* waiter -  Prints the process ID of the waiting process and 
 * decrements the semaphore by one and runs in a infinite loop. 
 */

void waiter() {
	kprintf ("Your waiting process id is: %d", getpid());
	wait(gsem);
	
	while(1) {
	
	}

}