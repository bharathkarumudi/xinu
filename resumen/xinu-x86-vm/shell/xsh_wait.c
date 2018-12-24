/* xsh_wait.c - xsh_wait */

#include <xinu.h>
#include <stdio.h>
#include <string.h>

/*-------------------------------------------------------------------------------------------------------
 * xsh_wait -   shell command to create a new process in waiting state. The process created with this 
                will have the prioroty set as INITPRIO (which is 20).
 *-------------------------------------------------------------------------------------------------------
 */
shellcmd xsh_wait(int nargs, char *args[])
{
	pri16   priority;
	char    ch;
    char    *chprio;
	pid32   pid;

    if (nargs == 1) {
        priority=INITPRIO;
    }
	
    else {
        kprintf("Too many arguments\n");
        return 1;
    }
    
    pid = create(waiter, 1024, priority, "Custom_Waiter", 0);

    resume(pid);	
    return 0;

}
