#include <xinu.h>

int CAPACITY = 10;
char* msgs[10];
int rear = 0;

void snd(), rec();
void main(void) {

	pid32 r1 = create(receive, 1024, 20, "receiver",0);
	resume(create(snd, 1024, 20, "sender",2, r1, "HELLO"));
	resume(create(snd, 1024, 20, "sender2",2, r1, "WORLD"));
	resume(create(snd, 1024, 20, "sender2",2, r1, "WELCOME"));
	resume(create(snd, 1024, 20, "sender2",2, r1, "To"));
	resume(create(snd, 1024, 20, "sender2",2, r1, "Xinu"));
	resume(create(snd, 1024, 20, "sender2",2, r1, "world!"));
	resume(r1);

}

void snd(pid32 pid, umsg32 msg) {

	send(pid, msg);

}

void rec() {

	umsg32 mssg = receive();

}