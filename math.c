#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char** argv) {

	int answer = 0;
	if (argc == 4) {
	       if (strcmp(argv[1],"+") == 0){	
		       answer = atoi(argv[2]) + atoi(argv[3]);
	       }
	       else if (strcmp(argv[1],"-") == 0){
		       answer = atoi(argv[2]) - atoi(argv[3]);
	
	       }
	       else if (strcmp(argv[1],"*") == 0){
                       answer = atoi(argv[2]) * atoi(argv[3]);

               }
	       else if (strcmp(argv[1],"/") == 0){
                       if (atoi(argv[3]) == 0) {
			       printf("Cant divide by 0\n");
			}
		       else {
		       		answer = atoi(argv[2]) / atoi(argv[3]);
		       }
               }
	       printf("%d \n", answer);
	}
	else if (argc == 3){
		int num2 = 0;
		if (strcmp(argv[1],"+") == 0){
                       answer = atoi(argv[2]);
		       scanf("%d" , &num2);
		       answer += num2;
               }
               else if (strcmp(argv[1],"-") == 0){
                       answer = atoi(argv[2]);
		       scanf("%d" , &num2);
                       answer -= num2;
               }
               else if (strcmp(argv[1],"*") == 0){
                       answer = atoi(argv[2]);
		       scanf("%d" , &num2);
                       answer *= num2;
               }
               else if (strcmp(argv[1],"/") == 0){
                       answer = atoi(argv[2]);
			scanf("%d" , &num2);
			if (num2 == 0) {
				printf("Cant divide by 0\n");
			}
			else{
				answer /= num2;
			}
	       }
	       printf("%d \n", answer);
	}	
	else if (argc == 2){
		answer = 0;
		int num2 = 0;
		int num3 = 0;
                if (strcmp(argv[1],"+") == 0){
                       scanf("%d", &num2);
                       scanf("%d" , &num3);
                       answer = num2 + num3;
               }
               else if (strcmp(argv[1],"-") == 0){
                       scanf("%d", &num2);
                       scanf("%d" , &num3);
                       answer = num2 - num3;
               }
               else if (strcmp(argv[1],"*") == 0){
                       scanf("%d", &num2);
                       scanf("%d" , &num3);
                       answer = num2 * num3;
               }
               else if (strcmp(argv[1],"/") == 0){
                       
                                scanf("%d", &num2);
                       		scanf("%d" , &num3);
				if (num3 == 0){
					printf("Cant divide by 0 \n");
				}
				else {
				answer = num2 / num3;
				}
               }
	       printf("%d \n", answer);
	}
	else if (argc <=1 ){
		printf("Not enough arguments\n");
		printf("%d \n", answer);
	}
	else if (argc >= 5){
		
		printf("Too many arguments\n");
		printf("%d \n", answer);
	}

	return answer;

}
