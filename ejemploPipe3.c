#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	
	int fd[2];
	pid_t pid;
	char saludoPadre[]="Buenos dias hijo.\0";
	char buffer[80];
	
	//Creo pipe
	pipe(fd);
	//Creo Proceso
	pid=fork();
	
	switch(pid){
	
	case -1: //Se produce un Error
		printf("NO SE HA PODIDO CREAR EL HIJO...");
		exit(-1);
		
	case 0: //Hijo Recibe
		//Cierra el descriptor de entrada
		close (fd[1]);
		//Leo el pipe
		read(fd[0], buffer, sizeof(buffer));
		printf("\tEL HIJO recibe algo del pipe: %s\n",buffer);
		break;

	default: //Padre Envia
		close(fd[0]);
		//Escribo en pipe
		write(fd[1], saludoPadre, strlen(saludoPadre));
		printf("EL PADRE envia mensaje al HIJO...\n");
		wait(NULL);//Espera a que finalice el proceso hijo
		break;
	}
	return 0;
	
}













