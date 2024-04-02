#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <pthread.h>

#define BUFFSIZE 4096

typedef struct _foo {
    int arg1;
    int arg2;
    char arg3;
    float arg4;
} foo_t;

void countWords(char haystack[], const char* word) {
    char lineText[BUFFSIZE];
    int occurrences = 0;

    FILE* fp = fopen(haystack, "r");
    while (fgets(lineText, BUFFSIZE, fp) != NULL) {
        char* textPointer = lineText;
        while ((textPointer = strstr(textPointer, word)) != NULL) {
            textPointer++;
            occurrences++;
        }
    }
    printf("%s - %d\n", haystack, occurrences);
    fclose(fp);
}

int worker(foo_t args) {
    int result = args.arg1 * args.arg2;
    return result;
}

void* fn(void* arg) {
    foo_t args = *(foo_t*)arg;
    int result = worker(args);
    int* retval = malloc(sizeof(int));
    *retval = result;
    return (void*)retval;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <numThreads> <file1> <file2> ... \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int numThreads = atoi(argv[1]);

    char userInput[BUFFSIZE];
    printf("Enter a word: ");
    scanf("%s", userInput);

    pthread_t threadIDs[numThreads];
    int* retval;

    for (int i = 2; i < argc; i++) {
        foo_t args;
        args.arg1 = 2;
        args.arg2 = 3;
        args.arg3 = 'A';
        args.arg4 = 3.14;

        FILE* fp = fopen(argv[i], "r");
        if (fp == NULL) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }

        pthread_create(&threadIDs[i - 2], NULL, fn, (void*)&args);
        pthread_join(threadIDs[i - 2], (void**)&retval);
	//        printf("%d\n", *retval);
        free(retval);

	//        countWords(argv[i], userInput);
    
    }

    for (int i = 2; i < argc; i++) {
        pid_t cpid = fork();

        if (cpid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (cpid == 0) { // Child
          //  FILE* fp = fopen(argv[i], "r");
	  //if (fp == NULL) {
	  //perror("fopen");
                //exit(EXIT_FAILURE);
		// }

            countWords(argv[i], userInput);
            //fclose(fp);
            exit(0);
        }
    }

    for (int i = 2; i < argc; i++) {
        wait(NULL);
    }

    return 0;
}
