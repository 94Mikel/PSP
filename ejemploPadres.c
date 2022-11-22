#include <stdio.h>
#include <unistd.h>

void main(void) //cuando ponemos void es que no nos va a devolver nada
{
	//pid_t sirve para declarar variables del mismo tipo
	pid_t id_pactual, id_padre;	
	
	id_pactual = getpid(); //getpid para sacar el identificador del proceso
	id_padre = getpid();

	printf("PID de este proceso: %d\n", id_pactual);
	printf("PID del proceso padre: %d\n", id_padre);
}
