/* Author: Bharath Karumudi
 * main.c - main, alice, bob 
 */
#include <xinu.h>

void alice(), bob();			/* Declaring the methods: alice and bob */

pid32 apid, bpid;				/* Creating the processes IDs: apid, bpid */
sid32 sem;						/* Declaring the semaphore sem */

void main(void) {

	sem = semcreate(0);									/* Initializing the semaphore with 0 */
	apid = create(alice, 1024, 40, "alice proc", 0);	/* Creating the process alice, with priority 40 */
	bpid = create(bob, 1024, 20, "bob proc", 0);		/* Creating the process bob, with priority 20 */
	resume(apid);										/* resuming alice process */
	resume(bpid);										/* resuming bob process */
	return OK;
}

/*
 * alice - Prints first statement and decrement the semaphore to block the process
 * and once the process runs again prints second statement and blocks the process again
 */

alice()
{
	printf("My first statement appears before Bob's second statement\n");
	wait(sem);											/* Decrement the semaphore - Negative sem  to block itself*/
	printf("This is Alice's second statement\n");
	kill(getpid());										/* kill the process id at the end */
}

/*
 * bob - Prints first statement and signal the sem to resume alice and 
 * again once runs, prints the second statement.
 */

bob() 
{
	printf("My first statement appears before Alices's second statement\n");
	signal(sem);										/* Increases sem count by one and this make the alice to run */
	printf("This is Bob's second statement\n");
	kill(getpid());										/* kill the process id at the end */

}
