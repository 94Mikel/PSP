//procesos3_4.c
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define SIZE 512

int main(){
pid_t pid;
int a[2], b[2], readbytes;
char buffer[SIZE];
pipe(a);
pipe(b);
pid = fork();

if (pid == 0){ 
    close(a[1]); 
    close(b[0]); 
    strcpy(buffer, "Hi \n");
    write(b[1], buffer, strlen(buffer));
    close(b[1]);

    while((readbytes=read(a[0], buffer, SIZE))>0)
    	write(1, buffer, size);
    close(a[0]);
} 

else {
    close(a[0]); 
    close(b[1]); 
    strcpy(buffer, "Hello.\n");
    write(a[1], buffer, strlen(buffer));
    close(a[1]);

    while((readbytes=read(b[0], buffer, SIZE))>0)
    	write(1, buffer, size);
    close(b[0]);
}

exit(0);
}
