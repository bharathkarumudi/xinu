/* xsh_signaln.c - xsh_signaln */

#include <xinu.h>
#include <stdio.h>
#include <string.h>


/*--------------------------------------------------------------------------------------------------------
 * xsh_signaln - shell command to signal the global semaphore. The semaphore will be signalled by
 				 one if no argument is passed and signalled by the value that is passed in the argument.
 *--------------------------------------------------------------------------------------------------------
 */

shellcmd xsh_resumen(int nargs, char *args[] ) {

	char *chpid;
	pid32 pid;
	int32 i=1; 

	while (i <= nargs) {

		chpid = args[i];
		pid = atoi(chpid);
		//pid = 10*pid + (ch - '0');
		//kprintf ("The passed PID: %d", pid);
		resume(pid);
		i++;
	}

	return 0;

}