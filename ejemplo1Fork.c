#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


void main() 
	{
	//pid_t sirve para declarar variables del mismo tipo
	pid_t pid, hijo_pid;	
	pid = fork(); //pid es el padre
	
	//hace para el fork
	if(pid == -1){ //Ha ocurrido un error
	printf("No se ha podido crear el proceso hijo...");
	exit(-1);
	}

	if(pid == 0){ //Nos encontramos en el proceso hijo 
		      //%d indica q sacaremos un nº entero x pantalla
	printf("Soy el proceso hijo \n\tMi PID es %d, El PID de mi padre es: %d.\n",		 		getpid(), getppid() );
	//getpid() -->%d
	//getppid()-->%d.\n	
	}
	else{ //Nos encontramos en el proceso padre

	hijo_pid = wait(NULL);		//espera la finalizacion del proceso hijo
	printf("Soy el proceso padre: \n\tMi PID es %d, El PID de mi padre es: %d.\n\tMi Hijo: %d 		termino.\n",getpid(),getppid(),pid);
	//getpid() -->%d
	//getppid()-->%d.\n
	//pid-->%d xxx .\n		
	}
	exit(0);
}
