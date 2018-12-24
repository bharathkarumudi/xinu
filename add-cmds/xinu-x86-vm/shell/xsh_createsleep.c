/* xsh_createsleep.c - xsh_createsleep */

#include <xinu.h>
#include <stdio.h>
#include <string.h>

/*----------------------------------------------------------------------------------------------
 * xsh_create - shell command to create a new process. Optionally, you can provide the 
 *              priority for the process, otherwise it will be set to INITPRIO (which is 20).
 *----------------------------------------------------------------------------------------------
 */

shellcmd xsh_createsleep(int nargs, char *args[])
{
	pri16   priority;
	char    ch;
    char    *chprio;
	pid32   pid;
    
    if (nargs == 1) {
        priority=INITPRIO;
        
    }
	
    else if ( nargs == 2 ) {
        chprio = args[1];
        ch = *chprio++;
        priority = 0;
        while(ch != NULLCH) {
            if ((ch <'0') || (ch > '9')) {
                kprintf("%s: non-digit in priority\n", args[1]);
                return 1;
            }
            priority = 10*priority + (ch - '0');
            ch = *chprio++;
        }

        if (priority < (pri16)MINKEY) {
            kprintf("%s: invalid prioirty\n", args[1]);
            return 1;
        }
 
    }
    else {
        kprintf("Too many arguments.\n");
        return 1;
    }
    pid = create(runforeversleep, 1024, priority, "Custom_Sleep", 0);
	
    resume(pid);
	
    return 0;


}
