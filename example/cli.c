// this is the CLI wrapper for testing the C

#include <stdio.h>
#include "example.h"

int main() {
  float* v = exampleOutput();

  printf("exampleOutput: %.6f", v[0]);
  // exampleInput(v);

  return 0;
}