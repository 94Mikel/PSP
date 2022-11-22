#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	
	//Creo las variables
	int fd[2];
	pid_t pid;
	char saludoHijo[]="Buenos dias padre.\0";
	char buffer[17];
	
	//Creo pipe
	pipe(fd);
	//Creo Proceso
	pid=fork();
	
	switch(pid){
	
	case -1: //Se produce un Error
		printf("NO SE HA PODIDO CREAR EL HIJO...");
		exit(-1);
		
	case 0: //Hijo envia
		//Escribo en el pipe
		write(fd[1], saludoHijo, strlen(saludoHijo));
		//Cierra el descriptor de entrada
		close (fd[1]);
		//Leo el pipe
		printf("EL HIJO envia algo al pipe.\n");
		break;

	default: //Padre recibe
		//Espera a que finalice el proceso hijo
		wait(NULL);
		//El padre lee
		read(fd[0], buffer, sizeof(buffer));
		close(fd[0]);
		//Muestra por pantalla
		printf("\tEL PADRE recibe algo del pipe: %s\n",buffer);
		break;
	}
	return 0;
	
}


		
