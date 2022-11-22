#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
int rc=0, estado, hijo;

if (argc!=1) {
printf("uso: %s\n",argv[0]);
rc=1;
exit(rc);
}
hijo = fork();

if (hijo != 0) {
wait(&estado);
printf("PADRE: pid=%d ppid=%d user-id=%d \n", getpid(), getppid(), getuid());
printf("Codigo de retorno del hijo: %d\n", estado);


}else{
printf("HIJO: pid=%d \n", getpid());}
exit(rc);
}
