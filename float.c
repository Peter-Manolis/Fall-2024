#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int powerFunction (int n){
  int returnVal = 1;
  for (int i = 0; i < n; i++) {
	   returnVal*= 2;
  }
  return returnVal;
}

unsigned int getFloatToUnsigned (float floatInput){
  return (*((unsigned int *) &floatInput));
}

unsigned int getBinaryToUnsigned (char * binaryInput){
  unsigned int returnVal = 0;
    int length = strlen(binaryInput);

    for (int i = 0; i < length; i++) {
        if (binaryInput[i] == '1') {
            returnVal = (returnVal << 1) | 1;
        }
	else if (binaryInput[i] == '0') {
            returnVal = returnVal << 1;
        }
    }
    return returnVal;
   
}

void binaryPrint(unsigned int a){
  for (int i = 31; i >= 0; i--) {
    int b = (a >> i) & 0x1;
    if (b == 1) {
            putchar('1');
    }

    else{
            putchar('0');
      }
    }
    printf("\n");
}

unsigned int getSign(unsigned int a){
  return ((a >> 31) & 0x1); 
}
float getMantissa(unsigned int a){
  float mantissa = 0x7FFFFF & a;
  mantissa = mantissa / 8388608;
  return mantissa;
}

int getExponent(unsigned int a){
  int exponent = a >> 23;
  exponent = (0xFF & exponent); 
  exponent = exponent - 127;
  if(exponent == -127){
    return -126;
  }
  else {
  return exponent;

  }
}


int main (int argc, char** argv){

  unsigned int unsignedValue = 0;
  float value = 0.0;
  int exponent = 0;
  int sign = 0;
  float mantissa = 0.0;
  
    if (strcmp(argv[1],"b") == 0){
      unsignedValue = getBinaryToUnsigned(argv[2]);
      value = *((float *) &unsignedValue);
      exponent = getExponent(unsignedValue);
      mantissa = getMantissa(unsignedValue);
	
    }
    else if (strcmp(argv[1], "f") == 0){
      value = strtof(argv[2], NULL);
      unsignedValue = getFloatToUnsigned(value);
      mantissa = getMantissa(unsignedValue);
      exponent = getExponent(unsignedValue);
      if ((exponent == -126) & (mantissa == 1.0)){
        mantissa = 0;
      }
    }
    
    sign = getSign(unsignedValue);
    printf("Binary: ");
    binaryPrint(unsignedValue);
    printf("Sign: %d\n", sign);
    printf("Exponent: %d\n", exponent);
    if(exponent == 0xFF){
      mantissa+=1;
        if(mantissa == 1.0){
          printf("Value: inf");
        }else{
	  mantissa+=.5;
	  printf("Value: nan");
	}
    }
    if (exponent != -126){
      mantissa += 1;
    }
     printf("Mantissa: %.7g\n", mantissa);
	
    if (strcmp(argv[1],"b") == 0){
      printf("Value: %.7g\n", value);
    }
    else if (strcmp(argv[1], "f") == 0){
      printf("Value: %.7g\n", value);
    }
}
