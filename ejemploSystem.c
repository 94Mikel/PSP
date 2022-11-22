/*Es la libreria*/
#include <stdio.h>
#include <stdlib.h>

/*Donde se realiza la funcion(El cuerpo principal)*/
void main ()
{	
	/*printf muestra por pantalla todo lo que haya entre comillas ""*/	
	printf("Ejemplo de uso de system():");
	/*\n --> nueva linea ó salto de linea \t tabulacion*/
	printf("\n\tListado del directorio actual y envio a un fichero:");
	/*%d te enseña lo que ha hecho el comando. un valor entero*/
	printf("%d",system("ls > ficsalida"));
	/**/
	printf("\n\tAbrimos con el gedit el fichero...");
	/**/
	printf("%d",system("gedit ficsalida"));	
	/**/
	printf("\n\tEste comando es erroneo: %d",system("ged"));
	/**/
	printf("\n\tFin de programa...\n");	
}



