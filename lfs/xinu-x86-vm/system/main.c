#include <xinu.h>

void proc1();


pid32 p1;

void main() {

	did32 fd; /* file device */
	uint32 filesize; /* size of file, in bytes */

	//fd = open(LFILE0,"file1","o");
	if (fd == (did32)SYSERR) {
		kprintf("Cannot open %s\n");
	}
}


