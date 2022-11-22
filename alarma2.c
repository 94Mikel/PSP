//alarma2.c
#include <signal.h>
#include <unistd.h>

void trapper(int);

int main(int argc, char *argv[]) {
	int i;
	signal(14, trapper); //14 significa SIGALARM
	printf("Identificador proceso: %d\n", getpid() );

	alarm(5);
	pause();
	alarm(3);
	pause();
		for(;;) {
			alarm(1);	
			pause();
			}		
	return 0;	
	}
	void trapper(int sig) {
	printf("RIIIIIIIIING!\n");
}
