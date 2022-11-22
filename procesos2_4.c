//procesos2_4.c
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 512

int main() {
	  pid_t pid;
	  int a[2], b[2], readbytes, estado;
	  char buffer[SIZE];
	  pipe(a);
	  pipe(b);

 if ((pid=fork()) == 0) {
	    close(a[1]);
	    close(b[0]);
    while((readbytes=read(a[0], buffer, SIZE))>0)
    write(1, buffer, readbytes);
    close(a[0]);
    strcpy(buffer, "Soy tu hijo, por el otro pipe...\n");
    write(b[1], buffer, strlen(buffer));
    close(b[1]);
  }
  else {
    close(a[0]);
    close(b[1]);
    strcpy(buffer, "Soy tu padre por un pipe.\n");
    write(a[1], buffer, strlen(buffer));
    close(a[1]);
    while((readbytes=read(b[0], buffer, SIZE))>0)
      write(1, buffer, readbytes );
    close(b[0]);
    wait(&estado);
  }  
  exit(0);
}
