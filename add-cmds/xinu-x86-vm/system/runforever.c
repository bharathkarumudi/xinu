/* runforever.c - runforever */
#include<xinu.h>

/* runforever - Prints the process ID and runs in a infinite loop */
void runforever() {
	kprintf ("Your process id is: %d", getpid());
	
	while(1) {
	
	}

}