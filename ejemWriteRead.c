#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void main(void){
	//Saludo esta vacio porq es un Array de caracteres
	//mirar asi quitarle una posicion al "Comentario"
	char saludo[] = "Un Saludo!!!\n";
	//espacio de memoria de 20posiciones
	char buffer[20];
	//fd es un escritor
	int fd, bytesleidos;
	
	//fichero se abre solo para escritura(,1)
	fd=open("texto.txt",1);
	
	if(fd == -1){
	printf("ERROR AL ABRIR EL FICHERO...\n");
	exit(-1);
	}
	
	printf("Escribo el saludo...\n");
	//strlen longitud del string	
	write(fd,saludo,strlen(saludo));	
	close(fd); //De esta manera cierro el fichero		
		
	//fichero se abre solo para lectura(,0)
	fd=open("texto.txt",0);
	printf("Contenido del Fichero: \n");	
	
	//leo bytes de uno en uno y lo guardo en buffer
	bytesleidos=read(fd,buffer,1);
	while(bytesleidos!=0){
	//pinto el byte leido
	//%s --> dato de tipo caracter
	printf("%s", buffer);
	//leo el otro byte y escribe en el printf superior
	bytesleidos=read(fd, buffer, 1);
	}
	close(fd);
	
}
















































