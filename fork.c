#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define MAX_SIZE 500
int main() {
     int pipefd[2];
     pid_t cpid;
     if (pipe(pipefd) == -1) {
       perror("pipe");
       exit(EXIT_FAILURE);
     }
     cpid = fork();
     if (cpid == -1) {
       perror("fork");
       exit(EXIT_FAILURE);
     }
     if (cpid == 0) {
      close(pipefd[1]);  
      char input[MAX_SIZE];
      printf("prompt$ ");
      read(pipefd[0], input, sizeof(input));

      if (strcmp(input, "id") == 0) {
      	execl("/usr/bin/id", "id", NULL);
      }
      else if (strcmp(input, "pwd") == 0) {
	execl("/usr/bin/pwd", "pwd", NULL);
      }
      else if (strcmp(input, "date") == 0) {
	execl("/usr/bin/date", "date", NULL);
      } 
      close(pipefd[0]);
      printf("$prompt$ ");
    }
    else {
     
      close(pipefd[0]);
      printf("prompt$ ");
      char input[MAX_SIZE];
      scanf("%s", input);
      write(pipefd[1], input, strlen(input) + 1);
      close(pipefd[1]);
       
      wait(NULL);
      printf("Done - %s\n", input);
    }
    return 0;
}
