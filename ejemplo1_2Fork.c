//LIBRERIAS
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

//Abuelo-hijo-nieto
//Hago la funcion
void main(){
//Hago las variables
	//pid_t es un tipo de datos .... despues la variable
	pid_t pid, hijo_pid, pid2, hijo2_pid;
	pid = fork(); //Soy el abuelo, creo a Hijo //al hijo(pid) se le da el valor de Fork //Estamos zona abuelo

if (pid == -1){ //si pid == -1 entonces, Ha ocurrido un error
	printf("No se ha podido crear el proceso hijo...");
	exit(-1);
}

if (pid == 0) { //Nos encontramos en el proceso hijo
	pid2 = fork(); //Soy el Hijo, creo a nieto //Estamos zona hijo
	switch(pid2)
    {
	case -1: //Error
	printf("No se ha podido crear el proceso hijo en el HIJO...");
	exit(-1);
	break;
	
	case 0: //proceso hijo
	printf("\t\tSoy el proceso NIETO %d; Mi Padre es = %d \n", getpid(), getppid());
	break;

	default: //proceso padre
	hijo2_pid=wait(NULL);
	//con el nieto ya acabado			//getpid es para sacar el proceso actual
	printf("\tSoy el proceso HIJO %d, Mi padre es: %d.\n", getpid(), getppid()); //aqui mi padre es (EL ABUELO)
	printf("\tMi hijo: %d termino.\n", hijo2_pid);
    }
   }
else{ //nos encontramos en el proceso padre
	hijo_pid = wait(NULL); //espera la finalizacion del proceso hijo
	printf("Soy el proceso ABUELO: %d, MI HIJO:%d terminó.\n",getpid(), pid);
    }
exit(0);
}











