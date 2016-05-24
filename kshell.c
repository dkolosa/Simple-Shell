
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


typedef void (*sighandler_t)(int);


void sighandle(int signal)
{
    printf("\nspshell->");
    fflush(stdout);
}

int main(int argc, char *argv[], char *envp[])
{
    char c = '\0';
    
    //Handle the interrupt signal
    signal(SIGINT, SIG_IGN);
    signal(SIGINT, sighandle);

    printf("\nspshell->");

    while(c != EOF){
	c = getchar();
	if(c == '\n') {
	  printf("\nspshell->");
	}
		
	printf("\n");
	return 0;
    }	

}
