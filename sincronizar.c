#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
/*----------------------------------------------*/
/* Gestion de señales en proceso PADRE*/

void gestion_padre (int segnal){
	printf("Padre recibe señal...%d\n",segnal);
}
/* gestion de señales en proceso hijo*/
void gestion_hijo(int segnal){
	printf("Hijo recibe señal...%d\n",segnal);
}
/*----------------------------------------------*/
int main(){
	int pid_padre, pid_hijo;

	pid_padre = getpid();
	pid_hijo = fork(); //Creamos hijo

switch(pid_hijo){
	case -1:
		printf("Error al crear el proceso hijo...\n");
		exit(-1);
	case 0: //ESTAMOS EN EL HIJO
		//tratamiento de la señal en proceso hijo
		signal(SIGUSR1, gestion_hijo);
		while(1){//bucle infinito
		sleep(1);
		kill(pid_padre, SIGUSR1);//envia señal al padre
		pause();//hijo espera hasta que llegue una señal de respuesta
	}
	break;

	default://PADRE
	//Tratamiento de la señal en proceso padre
	signal(SIGUSR1, gestion_padre);
	//padre espera poder recibir una señal de hijo
	while(1){
	pause();//padre espera hasta recibir una señal del hijo
	sleep(1);
	//ENIA SEÑAL AL HIJO
	kill(pid_hijo,SIGUSR1);
} 
  break;
}
  return 0;
}	
