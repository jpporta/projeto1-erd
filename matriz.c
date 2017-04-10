#include "lista.h"
#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initMatriz(float **M, int x, int y) {
  M = malloc(x * sizeof(float *));
  for (int i = 0; i < x; i++) {
    M[i] = (float *)malloc(y * sizeof(float));
  }
}
void eliminaMatriz(float **dobby, int x) {
  for (int i = 0; i < x; i++) {
    free(dobby[i]);
  }
}
