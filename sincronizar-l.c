#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
/*----------------------------------------------*/
/* Gestion de señales de proceso HIJO*/
//void manejador es la funcion
void manejador (int segnal){
	printf("Hijo recibe señal...%d\n", segnal);
}
/*----------------------------------------------*/
int main(){
	int pid_hijo; //pid_hijo es el proceso
	pid_hijo = fork(); //Creamos hijo

switch(pid_hijo){
	case -1:
		printf("Error al crear el proceso hijo...\n");
		exit(-1);
	case 0: //ESTAMOS EN EL HIJO //Signal decide lo que se hara al recibir la señal y manejador
		signal(SIGUSR1, manejador); //MANEJADOR DE SEÑAL EN HIJO
		while(1);{
	};
	break;
	default: //PADRE envia 2 señales AL HIJO
	//LA SEÑAL LA RECOGE A TRAVES DEL MANEJADOR
	sleep(1);
	kill(pid_hijo, SIGUSR1);//ENVIA LA SEÑAL 1 AL HIJO
	sleep(1);
	kill(pid_hijo, SIGUSR1);//ENVIA LA SEÑAL 2 AL HIJO	
	sleep(1);	
	break;
}
	return 0;
}

