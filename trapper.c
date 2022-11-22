// trapper.c 
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void trapper(int);
	int main(int argc, char *argv[]){
int i;
	for(i=1;i<=9;i++)
	signal(i, trapper);
	printf("Identificador del proceso: %d\n", getpid() );
	pause();
	printf("Continuando...\n");
	printf("Termino.\n");
	return 0;
}
	void trapper(int sig){
	printf("\nSeñal que he recogido: %d\n", sig);
}
