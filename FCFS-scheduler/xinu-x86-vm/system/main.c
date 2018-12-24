
#include<xinu.h>

void p2(), p3(), p4();

void main (void) {

	pid32 pid2, pid3, pid4;
	printf("Inside Main \n");

	pid2 = create(p2, 1024, 5,  "p2", 0);
	pid3 = create(p3, 1024, 10, "p3", 0);
	pid4 = create(p4, 1024, 20, "p4", 0);

	resume(pid2);
	resume(pid3);
	resume(pid4);

	//return OK;
}

void p2() {

	printf("Process 2 is running...\n");
	sleep(15);
	while (1) {
		printf("Process 2 is running...\n");
	}

}

void p3() {
	printf("Process 3 is running...\n");
	sleep(15);
	while(1) {
		printf("Process 3 is running...\n");
	}
}

void p4() {
	printf("Process 4 is running...\n");
	sleep(15);
	while(1) {
		printf("Process 4 is running...\n");
	}
}
