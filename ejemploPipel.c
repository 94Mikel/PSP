#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(){

	int fd[2];
	char buffer[30];
	pid_t pid;
	//Se crea el pipe
	pipe(fd);
	//Se crea el proceso hijo
	pid=fork();
	
	//Switch para diferenciar los casos
	switch(pid){
	case -1: //Se produce un Error
		printf("NO SE HA PODIDO CREAR EL HIJO...");
		exit(-1);
		break;
	case 0: //Hijo
		printf("EL HIJO ESCRIBE EN EL PIPE...\n");
		//El escribir coge el descriptor(fd).VALOR 1 XQ ESCRIBE, el mensaje y el buffer de 10 			digitos
		write(fd[1], "Hola Papi",10);
		break;
	default: //Padre
		wait(NULL);//Espera a que finalice el proceso hijo
		printf("EL PADRE LE DEL PIPE...\n");
		read(fd[0], buffer, 10);
		printf("\tMensaje leido: %s\n", buffer); //%s --> porque es una cadena de caracteres
		break;
	}
}
