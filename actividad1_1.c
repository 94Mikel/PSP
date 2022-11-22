#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


void main(//Tambien se le puede poner con esto dentro del main -->int argc, char *argv[]) 
{
	//Declaro la variable y le doy un valor. 6 en este caso.	
	int valor=6;

	//pid_t variable para padre e hijo
	pid_t pid,Hijo_pid;
	pid= fork();//Soy el padre, creo el hijo

	printf("El Valor inicial de la variable es: %d.\n",valor);
	
	//pid_t variable para padre e hijo
	pid_t pid,Hijo_pid;
	pid= fork();//Soy el padre, creo el hijo

	if(pid==-1) //si pid == -1 entonces, Ha ocurrido un error
	{
		printf("No se ha podido crear el proceso hijo...");
		exit(-1);
	}
	if(pid==0) //Nos encontramos en Proceso hijo
	{	//Para restar
		valor=valor-5;
		printf("Variable en proceso Hijo: %d.\n",valor);
	}
	else //Nos encontramos en Proceso padre
	{
		Hijo_pid = wait(NULL); //espera la finalizacion del proceso hijo
		//Para Sumar
		valor=valor+5;
		printf("Variable en proceso Padre: %d.\n",valor);
	}
	exit(0);
}
