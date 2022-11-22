//alarma.c
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void trapper(int);
int main(int argc, char *argv[]){
	// Programa
	int i; //Si no pongo el int i tampoco pasa nada

	printf("Id del proceso: %d\n",getpid()); 
	signal(14, trapper);
	
	
	pause(); //hago este pause para q desde otra terminal me de tiempo a pararlo. kill -14 idProceso
	alarm(5);
	pause();
	

}

void trapper(int sig){
	//printf("RING-RING-RING!\n");
}
