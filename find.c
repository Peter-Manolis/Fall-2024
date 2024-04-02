#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define BUFFSIZE 4096

int countWord(FILE *fp, char word[]){
  
  char lineText[BUFFSIZE];
  int occurrences = 0;
  
  while (fgets(lineText, BUFFSIZE, fp) != NULL){
    char * textPointer = lineText;
    while ( (textPointer = strstr(textPointer, word)) != NULL ){
	textPointer++;
	occurrences++;
      }
	    
    
  }
  //printf("%p - %d\n", &fp, occurrences);
  return occurrences;
}

int main (int argc, char ** argv){
  int N = argc;
  pid_t cpid;

  
  char userInput[BUFFSIZE];
  printf("Enter a word\n");
  scanf("%s", userInput);
  
  for (int i =1; i<N; i++){
    cpid = fork();

    if (cpid == -1) {
      perror("fork");
      exit(EXIT_FAILURE);
    }
    if (cpid == 0) { //Child
      FILE * fp;

     
      if ((fp = fopen(argv[i], "r")) == NULL){
	  exit(-1);
      }
      else{
       int wordCount = countWord(fp, userInput);
       printf("%s - %d\n", argv[i], wordCount); 
      }
      fclose(fp);
      exit(0);
            
    }
  }
  for (int i = 1; i < argc; i++) {
     wait(NULL);
  }
}
