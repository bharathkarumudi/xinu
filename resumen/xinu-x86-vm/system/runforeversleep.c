/* runforeversleep.c - runforever */

/* runforever - Prints the process ID and runs in a infinite loop */
void runforeversleep() {

	sleep(10);
	kprintf ("Your process id is: %d", getpid());
	
	while(1) {
	
	}

}