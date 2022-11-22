#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//Abuelo-hijo-nieto

void main(){
						//pid 1ºer hijo, pid2 2ºdo hijo
	pid_t pid, hijo_pid, pid2, hijo2_pid; //hijo_pid y hijo_pid2 los creamos para las esperas

	int fd1[2];
	int fd2[2];
	
	char saludoAbuelo[]="Saludos del Abuelo.\0";
	char saludoPadre[]="Saludos del Padre.\0";
	char saludoHijo[]="Saludos del Hijo.\0";
	char saludoNieto[]="Saludos del Nieto.\0";

	char buffer[80]="";

	pipe(fd1);
	pipe(fd2);
	
	//Soy el abuelo, creo el hijo
	pid=fork();

	if (pid == -1){ //si pid == -1 entonces, Ha ocurrido un error
		printf("No se ha podido crear el proceso hijo...");
		exit(-1);
	}

	if (pid == 0) { //Estamos en el proceso hijo
		pid2=fork();//Soy el hijo, creo al nieto
		switch(pid2) {	
			
		case -1: //error
		printf("No se ha podido crear el proceso hijo...");
		exit(-1);
		break;
			
		case 0: //proceso hijo (nieto)
		//NIETO RECIBE
		//cierra el descriptor de entrada
		close(fd2[1]);//1 --> es de escritura
		//leo el pipe
		read(fd2[0],buffer,sizeof(buffer)); //0 es de lectura
		printf("\t\tNIETO RECIBE mensaje de su padre: %s\n",buffer);	

		//NIETO ENVIA
		printf("\t\tNIETO ENVIA MENSAJE a su padre...\n");
		close(fd1[0]);
		write(fd1[1], saludoNieto, strlen(saludoNieto));		
		break;

		default: //proceso padre (hijo)
		//HIJO RECIBE
		close(fd1[1]);//cierra el descriptor de entrada. SE CIERRA SIEMPRE EL QUE NO USAMOS
		read(fd1[0],buffer,sizeof(buffer)); //leo el pipe
		printf("\tHIJO RECIBE mensaje de su ABUELO: %s\n",buffer);	
		
		//HIJO ENVIA a su hijo
		close(fd2[0]);
		write(fd2[1], saludoPadre, strlen(saludoPadre));
		hijo2_pid=wait(NULL);//espero al hijo
	
		//RECIBE DE SU HIJO
		close(fd1[1]);//cierra el descriptor de entrada
		read(fd1[0],buffer,sizeof(buffer)); //leo el pipe
		printf("\tHIJO RECIBE mensaje de su hijo: %s\n",buffer);	

		//HIJO ENVIA A SU PADRE
		close(fd2[0]);//cierra el descriptor de entrada
		write(fd2[1], saludoHijo, strlen(saludoHijo));	
		printf("\tHIJO ENVIA MENSAJE a su padre...\n",buffer); //no le he puesto buffer detras de \n
		}
	}
	else{ //Nos enconrtramos en el ABUELO
		//ABUELO ENVIA	
		printf("ABUELO ENVIA MENSAJE aL HIJO...\n");
		close(fd1[0]);
		write(fd1[1], saludoAbuelo, strlen(saludoAbuelo));	
		hijo_pid=wait(NULL);//Espera a que acabe el hijo
		
		//PADRE RECIBE
		close(fd2[1]);//cierra el descriptor de entrada
		read(fd2[0],buffer,sizeof(buffer)); //leo el pipe
		printf("EL ABUELO RECIBE mensaje DEL HIJO: %s\n",buffer);
			
		
	}
	exit(0);

}
