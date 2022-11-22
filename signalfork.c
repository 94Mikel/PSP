// signalfork.c
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void trapper(int sig){
	signal(sig, trapper);
	printf("SIGUSR1\n");
}

int main(int argc, char *argv[]){
	pid_t padre, hijo;
	padre = getpid();
	signal( SIGUSR1, trapper );

if ( (hijo=fork()) == 0 ) { 
	
	/* hijo */
	sleep(1);
	kill(padre, SIGUSR1);
	sleep(1);
	kill(padre, SIGUSR1);
	sleep(1);
	kill(padre, SIGUSR1);
	sleep(1);
	kill(padre, SIGKILL);
	exit(0);
      }
	else{ 
	/* padre */
	for (;;);
      }
	return 0;
    }
