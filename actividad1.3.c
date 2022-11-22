/* ---------------------ENUNCIADO--------------------------
un hijo envie 3 señales SIGUSR1 a su padre y despues
envie una señal SIGKILL para que el proceso padre termine */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>

/* Gestion de señales en proceso PADRE*/

void gestion_hijo (int segnal){
	printf("Padre recibe señal...%d\n",segnal);
}


int main(){
	//Hago variables
	int pid_padre, pid_hijo;

	pid_padre = getpid();
	pid_hijo = fork(); //Creamos hijo

switch(pid_hijo){
	//Si se produce un error
	case -1:
		printf("Error al crear el proceso hijo...\n");
		exit(-1);
	case 0: //ESTAMOS EN EL HIJO
		//tratamiento de la señal en proceso hijo

		sleep(1);//el (1) es el tiempo en seg que tarda en mostrar mensaje
		kill(pid_padre, SIGUSR1);//envia señal1 al padre
		sleep(1);
		kill(pid_padre, SIGUSR1);//envia señal2 al padre
		sleep(1);
		kill(pid_padre, SIGUSR1);//envia señal3 al padre
		sleep(1);
		kill(pid_padre,SIGKILL);
		//SIGKILL hace que el proceso muera
	break;

	default://PADRE
	//Tratamiento de la señal en proceso padre
	signal(SIGUSR1, gestion_hijo);
	//padre espera poder recibir una señal de hijo
	while(1){
		} 
  break;
}
  return 0;
}	

