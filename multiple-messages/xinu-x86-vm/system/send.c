/* send.c - send */

#include <xinu.h>
#include <stdlib.h>

extern char* msgs[];
extern int rear;
extern int CAPACITY;

/*------------------------------------------------------------------------
 *  send  -  pass a message to a process and start recipient if waiting
 *------------------------------------------------------------------------
 */
syscall	send(
	  pid32		pid,		/* ID of recipient process	*/
	  umsg32	msg		/* contents of message		*/
	)
{
	intmask	mask;			/* saved interrupt mask		*/
	struct	procent *prptr;		/* ptr to process' table entry	*/

	mask = disable();
	if (isbadpid(pid)) {
		restore(mask);
		return SYSERR;
	}

	prptr = &proctab[pid];
	if ((prptr->prstate == PR_FREE)) {
		restore(mask);
		return SYSERR;
	}

/* MESSAGE STORAGE ADDITION */

	if (rear > CAPACITY) {
		return SYSERR;
	}

	msgs[rear] = msg;
	rear = rear + 1;


	//msgs[rear] = "\0";


	//int size_A = sizeof(msgs);
	//rear = (rear+1)%CAPACITY;
	//size++;
	//msgs[rear] = msg;
	//kprintf("Message in send: %s\n", msgs[0] );
	//kprintf("Message in send: %s\n", msgs[1] );
	//kprintf("Message in send: %s\n", msgs[2] );
	//kprintf("END----\n");

//END OF MESSAGE STORAGE */


   /* struct node *temp;
 
    //temp = (struct node*)malloc(sizeof(struct node));
    temp->data = msg;
    temp->link = NULL;
    if (rear  ==  NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->link = temp;
        rear = temp;
    }    
*/


	prptr->prmsg = msg;		/* deliver message		*/
	prptr->prhasmsg = TRUE;		/* indicate message is waiting	*/

	/* If recipient waiting or in timed-wait make it ready */

	if (prptr->prstate == PR_RECV) {
		ready(pid, RESCHED_YES);
	} else if (prptr->prstate == PR_RECTIM) {
		unsleep(pid);
		ready(pid, RESCHED_YES);
	}
	restore(mask);		/* restore interrupts */
	return OK;
}
