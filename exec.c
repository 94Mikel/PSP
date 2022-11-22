// exec.c

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

main() {

execl("/bin/mkdir", "-v", "gari", 0);


	printf("No deberia llegar aqui\n");
	exit(-1);
	
}
