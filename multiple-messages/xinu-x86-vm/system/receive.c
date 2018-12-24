/* receive.c - receive */

#include <xinu.h>

extern char* msgs[];
extern int rear;
extern int CAPACITY;


/*------------------------------------------------------------------------
 *  receive  -  wait for a message and return the message to the caller
 *------------------------------------------------------------------------
 */
umsg32	receive(void)
{
	intmask	mask;			/* saved interrupt mask		*/
	struct	procent *prptr;		/* ptr to process' table entry	*/
	umsg32	msg;			/* message to return		*/

	mask = disable();
	prptr = &proctab[currpid];
	if (prptr->prhasmsg == FALSE) {
		prptr->prstate = PR_RECV;
		resched();		/* block until message arrives	*/
	}
	//msg = prptr->prmsg;		/* retrieve message		*/
	//prptr->prhasmsg = FALSE;	/* reset message flag		*/
	//restore(mask);

	msg = msgs[0];
	int32 i;

	for (i=0; i<rear; i=i+2) {
		kprintf ("\nMessage is: %s",  msgs[i]);
		//msgs[i] = msgs[i+1];
	}
	rear = rear - 1;


	restore(mask);
	 //END OF RETURN MESSAGE */

/*
	struct node *temp;
    temp = front;
    if (front == NULL)
    {
        printf("queue is empty \n");
        front = rear = NULL;
    }
    else
    {    
        msg=front->data;
        front = front->link;
        //free(temp);
    }
    */

	return msg;
}
