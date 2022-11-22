//programa9.c

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void comprobar(int sig) {
	char resp;
	printf("Terminar? (s/n): ");
	scanf("%c", &resp);

	if (resp == 's') 
	exit(0);
}

int main(void) {
	int i, j;
	signal(SIGINT, SIG_IGN);

	for (i=0; i<10; i++) {
		printf("Ni caso a ^C\n");
		sleep(2);
	}
	signal(SIGINT, SIG_DFL);

	for (i=0; i<10; i++) {
		printf("Hago caso a ^C\n");
		sleep(2);
	}
	signal(SIGINT, comprobar);

	for (i=0; i<10; i++) {
		printf("Ahora lo que tu quieras\n");
		sleep(2);
	}
	exit(0);
}

