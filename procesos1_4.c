//procesos1_4.c
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 512

int main() {
	pid_t pid;
	int p[2], readbytes, estado;
	char buffer[SIZE];
	pipe(p);
  	pid = fork();

if(pid != 0){
    close(p[0]); 
    strcpy(buffer, "Este texto llega por la tuberia.\n");
    write(p[1], buffer, strlen(buffer));
    close(p[1]);
    wait(&estado);  
 }
  else {
    close(p[1]);
    while((readbytes=read(p[0], buffer, SIZE))>0)
      write(1,buffer,readbytes);
    close(p[0]);
  }
  exit(0);
}
