#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

char command[256];
void main(){
	int rtn;
	while( fgets(command, 256, stdin) != "exit"){
		printf(">");
		command[strlen(command-1)]=0;
		if(fork() == 0){
			execlp(command, NULL);
			perror(command);
			exit(errno);
		}
		else{
			wait(&rtn);
			printf("child process return %d\n", rtn);
		}
	}
}
