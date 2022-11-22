//Fifo crea

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void){

	int fp;
	int p, bytesleidos;
	char saludo[] = "Un saludo!!!\n", buffer[10];
	
	//Permiso de lectura y escritura
	p=mknod("FIFO2", S_IFIFO|0666,0);
	
	if (p==-1){
		printf("HA OCURRIDO UN ERROR...\n");			
		exit(0);		
	}
	
	while(1){
		fp = open("FIFO2",0);
		bytesleidos=read(fp,buffer,1);	
		printf("OBTENIENDO INFORMACION...");	
		while(bytesleidos!=0){
		printf("%s",buffer);
		//leo otro byte
		bytesleidos=read(fp,buffer,1);
	}
	close(fp);
	}
	return(0);
}




