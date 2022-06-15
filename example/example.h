// this implements th API that will be wrapped

#include <stdio.h>

// takes a a float-array as input, prints 1st element
void exampleInput (float* ia) {
  printf("exampleInput: %.6f", ia[0]);
}

float* exampleOutput () {
  float tester[5] = {1,2,3,4};
  return tester;
}
